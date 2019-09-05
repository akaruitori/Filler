/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/05 18:17:33 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** player.write_to_player("$$$ exec p#{i} : [#{player.file_name}]\n")
*/

char		*find_player_line()
{
	char	*line;

	line = NULL;
	while(get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strnequ(line, PLAYER_EXEC_START, PLAYER_EXEC_START_LEN))
			return (line);
		ft_strdel(&line);
	}
	return (NULL);
}

int				read_player_no(char *line)
{
	return (ft_atoi(line + PLAYER_NO_POS));
}

t_player		*init_player(int player_no)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->sym = (player_no == 1 ? 'O' : 'X');
	new->latest_sym = (player_no == 1 ? 'o' : 'x');
	return (new);
}

int			save_players(t_game *game, char *line)
{
	int		self_no;

	self_no = read_player_no(line);
	if (self_no != 1 && self_no != 2)
		return (0);
	game->self = init_player(self_no);
	game->enemy = init_player(self_no == 1 ? 2 : 1);
	if (!game->self || !game->enemy)
		return (0);
	return (1);
}

int			read_players(t_game *game)
{
	char	*line;

	if (!(line = find_player_line()) ||
		!(save_players(game, line)))
		return (0);
	return (1);
}

t_game		*init_game()
{
	t_game	*new;

	if (!(new = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	new->map = NULL;
	new->self = NULL;
	new->enemy = NULL;
	return (new);
}

t_pos			*read_coords(char *line)
{
	int			x;
	int			y;
	t_pos		*coords;

	if (!(y = (int)ft_strtol(line, &line, 10))
		|| !(x = (int)ft_strtol(line, NULL, 10)))
		return (NULL);
	coords = (t_pos *)malloc(sizeof(t_pos));
	if (!coords)
		return (NULL);
	coords->x = x;
	coords->y = y;
	return (coords);
}

t_pos			*read_map_sizes(void)
{
	char	*line;
	t_pos	*map_sizes;

	if (get_next_line(STDIN_FILENO, &line) < 1)
		return (NULL);
	if (!ft_strnequ(line, MAP_COORD_PREFIX, MAP_COORD_PREFIX_LEN))
		return (NULL);
	map_sizes = (t_pos *)malloc(sizeof(t_pos));
	if (!map_sizes || !(map_sizes = read_coords(line + MAP_COORD_PREFIX_LEN)))
		return (NULL);
	return (map_sizes);
}

void		save_start_pos(t_pos **player_pos, int x, int y)
{
	t_pos	*new;
	t_pos	*temp;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		return ;
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (*player_pos)
	{
		temp = *player_pos;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*player_pos = new;
}

int			read_start_pos(t_game *game, t_pos *map_sizes,
							t_pos **self_pos, t_pos **enemy_pos)
{
	char	*line;
	int		lines_to_read;
	int		i;

	lines_to_read = map_sizes->y + 1;
	while (lines_to_read > 0)
	{
		if (get_next_line(STDIN_FILENO, &line) < 1)
			return (0);
		i = X_MAP_OFFSET;
		while (line[i])
		{
			if (line[i] == game->self->sym)
				save_start_pos(self_pos, i - X_MAP_OFFSET, 
								map_sizes->y - lines_to_read);
			else if (line[i] == game->enemy->sym ||
					line[i] == game->enemy->latest_sym)
				save_start_pos(enemy_pos, i - X_MAP_OFFSET, 
								map_sizes->y - lines_to_read);
			i++;
		}
		lines_to_read--;
	}
	return ((!*self_pos || !*enemy_pos) ? 0 : 1);
}

int			ft_max(int a, int b)
{
	return ((a >= b) ? a : b);
}

int			ft_min(int a, int b)
{
	return ((a >= b) ? b : a);
}

/*
** https://learnc.info/c/fast_array_allocation.html
*/

int			fill_heat_map_cell(int x, int y, t_pos **self_pos,
								t_pos **enemy_pos)
{
	if ((*self_pos) && ((*self_pos)->x == x && (*self_pos)->y == y))
	{
		*self_pos = (*self_pos)->next;
		return (-1);
	}
	else if ((*enemy_pos) && ((*enemy_pos)->x == x && (*enemy_pos)->y == y))
	{
		*enemy_pos = (*enemy_pos)->next;
		return (0);
	}
	else
		return (INT_MAX);

}

int			**create_heat_map(t_pos *map_sizes, t_pos *self_pos,
								t_pos *enemy_pos)
{
	int		**heat_map;
	int		y;
	int		x;

	y = 0;
	if (!(heat_map = (int **)malloc(sizeof(int *) * map_sizes->y +
								sizeof(int) * map_sizes->x * map_sizes->y)))
		return (NULL);
	while (y < map_sizes->y)
	{
		heat_map[y] = (int *)(heat_map + map_sizes->y) + y * map_sizes->x;
		x = 0;
		while (x < map_sizes->x)
		{
			heat_map[y][x] = fill_heat_map_cell(x, y, &self_pos, &enemy_pos);
			x++;
		}
		y++;
	}
	return (heat_map);
}

t_map		*init_map(t_pos *map_sizes, t_pos *self_start_pos,
						t_pos *enemy_start_pos)
{
	t_map	*new;
	int		**heat_map;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->sizes = map_sizes;
	heat_map = create_heat_map(map_sizes, self_start_pos, enemy_start_pos);
	if (!heat_map)
		return (NULL);
	new->heat_map = heat_map;
	return (new);
}

void		calculate_heat_for_pos(int enemy_x, int enemy_y, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->sizes->y)
	{
		x = 0;
		while (x < map->sizes->x)
		{
			if (map->heat_map[y][x] > 0)
			{
				map->heat_map[y][x] = ft_min(
							ft_max(ft_abs(enemy_x - x), ft_abs(enemy_y - y)),
									map->heat_map[y][x]);
			}
			x++;
		}
		y++;
	}
}

void		update_heat_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->sizes->y)
	{
		x = 0;
		while (x < game->map->sizes->x)
		{
			if (game->map->heat_map[y][x] == 0)
				calculate_heat_for_pos(x, y, game->map);
			x++;
		}
		y++;
	}
}

//
void		print_heat_map(t_map *map)
{
	int		x;
	int		y = 0;

	while (y < map->sizes->y)
	{
		x = 0;
		while (x < map->sizes->x)
		{
			printf("%3d", map->heat_map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
//

int			create_map(t_game *game)
{
	t_pos	*map_sizes;
	t_pos	*self_start_pos;
	t_pos	*enemy_start_pos;

	self_start_pos = NULL;
	enemy_start_pos = NULL;
	if (!(map_sizes = read_map_sizes()) ||
		!(read_start_pos(game, map_sizes, &self_start_pos, &enemy_start_pos)))
		return (0);
	game->map = init_map(map_sizes, self_start_pos, enemy_start_pos);
	if (!game->map)
		return (0);
	print_heat_map(game->map); //
	update_heat_map(game);
	print_heat_map(game->map); //
	return (1);
}

int			filler()
{
	t_game	*game;

	game = init_game();
	if (!game || !read_players(game) || !create_map(game))
		return (0);
	// while (game)
	// {

	// }
	return (1);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (!filler())
	{
		perror("An error occured in filler function");
		return (1);
	}
	return (0);
}
