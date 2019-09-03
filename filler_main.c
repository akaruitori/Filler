/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/03 18:26:22 by dtimeon          ###   ########.fr       */
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

t_pos			*read_map_sizes()
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

int			read_start_pos(t_game *game, t_pos *map_sizes,
							t_pos *self_start_pos, t_pos *enemy_start_pos)
{
	char	*line;
	int		lines_to_read;
	char	*game_piece;

	lines_to_read = game->map->sizes->y + 1;
	while (lines_to_read > 0)
	{
		if (get_next_line(STDIN_FILENO, &line) < 1)
			return (0);
		if (game_piece = ft_strchr(line, game->self->sym))
		{
			self_start_pos = (t_pos *)malloc(sizeof(t_pos));
			self_start_pos->y = game->map->sizes->y - lines_to_read;
			self_start_pos->x = game_piece - line - X_MAP_OFFSET;
		}
		if (game_piece = ft_strchr(line, game->enemy->sym))
		{
			enemy_start_pos = (t_pos *)malloc(sizeof(t_pos));
			enemy_start_pos->y = game->map->sizes->y - lines_to_read;
			enemy_start_pos->x = game_piece - line - X_MAP_OFFSET;
		}
		lines_to_read--;
	}
}

int			create_map(t_game *game)
{
	t_pos	*map_sizes;
	t_pos	*self_start_pos;
	t_pos	*enemy_start_pos;

	if (!(map_sizes = read_map_sizes(game)) ||
		!(read_start_pos(game, map_sizes, self_start_pos, enemy_start_pos)))
		return (0);
	game->map = init_map(map_sizes, self_start_pos, enemy_start_pos);
	if (!game->map)
		return (0);
	return (1);
}

int			filler()
{
	t_game	*game;

	game = init_game();
	if (!game || !read_players(game) || !create_map(game))
		return (0);

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
