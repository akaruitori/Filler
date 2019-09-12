/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/12 21:15:36 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		read_till_newline()
{
	char	c;
	int		bytes_read = 1;

	c = '\0';
	while (c != '\n' && bytes_read)
		bytes_read = read(STDIN_FILENO, &c, 1);
}

/*
** player.write_to_player("$$$ exec p#{i} : [#{player.file_name}]\n")
*/

char		*find_player_line(t_game *game)
{
	char	*line;
	size_t	bytes_read;

	line = ft_strnew(PLAYER_EXEC_LEN + 1);
	if ((bytes_read = read(STDIN_FILENO, line, PLAYER_EXEC_LEN)) > 0)
	{
		if (game->log)
			fwrite("Attemt to read player line\n", sizeof(char), 27, game->log);
		if (ft_strnequ(line, PLAYER_EXEC_START, PLAYER_EXEC_START_LEN))
		{
			if (game->log)
			{
				fwrite(line, sizeof(char), ft_strlen(line), game->log);
				fwrite(" is read\n", sizeof(char), 9, game->log);
			}
			read_till_newline();
			return (line);
		}
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
	char	*self_no_str;

	self_no = read_player_no(line);
	if (game->log)
	{
		self_no_str = ft_llint_to_str_base(self_no, 10);
		fwrite("Player no is ", sizeof(char), 13, game->log);
		fwrite(self_no_str, sizeof(char), ft_strlen(self_no_str), game->log);
	}
	if (self_no != 1 && self_no != 2)
		return (0);
	game->self = init_player(self_no);
	game->enemy = init_player(self_no == 1 ? 2 : 1);
	if (!game->self || !game->enemy)
		return (0);
	if (game->log)
		fwrite("\nPlayers are created\n", sizeof(char), 21, game->log);
	return (1);
}

int			read_players(t_game *game)
{
	char	*line;

	if (!(line = find_player_line(game)) ||
		!(save_players(game, line)))
		return (0);
	return (1);
}

t_game		*init_game(int log_flag)
{
	t_game	*new;
	FILE	*log;

	if (!(new = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	new->map = NULL;
	new->self = NULL;
	new->enemy = NULL;
	new->self_piece = NULL;
	new->choosed_pos = NULL;
	if (log_flag)
	{
		log = fopen(LOG_FILENAME, "w");
		new->log = log;
	}
	else
		new->log = NULL;	
	fwrite("Game struct initialized\n", sizeof(char), 24, new->log);
	return (new);
}

char			*read_two_ints()
{
	char		*line;
	int			i;

	i = 0;
	line = ft_strnew(24);
	while (i < 11)
	{
		if (read(STDIN_FILENO, &line[i], 1) < 1)
			return (NULL);
		if (i > 0 && line[i] == ' ')
			break ;
		if (!ft_isdigit(line[i]))
			return (NULL);
		i++;
	}
	while (i++ < 24)
	{
		if (read(STDIN_FILENO, &line[i], 1) < 1 ||
			!(ft_isdigit(line[i]) || (line[i] == ':')) ||
			((line[i - 1] == ' ') && (line[i] == ':')))
			return (NULL);
		if (line[i] == ':')
			break;
	}
	return (line);
}

t_pos			*read_coords(t_game *game)
{
	int			x;
	int			y;
	char		*line;
	t_pos		*coords;

	if (!(line = read_two_ints()) ||
		!(y = (int)ft_strtol(line, &line, 10))
		|| !(x = (int)ft_strtol(line, NULL, 10)))
		return (NULL);
	if (game->log)
	{
		fwrite("\nMap sizes line: ", sizeof(char), 17, game->log);
		fwrite(line, sizeof(char), ft_strlen(line), game->log);
	}
	coords = (t_pos *)malloc(sizeof(t_pos));
	if (!coords)
		return (NULL);
	coords->x = x;
	coords->y = y;
	read_till_newline();
	return (coords);
}

void		log_map_sizes(t_game *game, t_pos *map_sizes)
{
	char	*x;
	char	*y;

	if (game->log)
	{
		x = ft_llint_to_str_base(map_sizes->x, 10);
		y = ft_llint_to_str_base(map_sizes->y, 10);
		fwrite("Map sizes: ", sizeof(char), 11, game->log);
		fwrite(y, sizeof(char), ft_strlen(y), game->log);
		fwrite(" ", sizeof(char), 1, game->log);
		fwrite(x, sizeof(char), ft_strlen(x), game->log);
		fwrite("\n", sizeof(char), 1, game->log);
	}
}

t_pos			*read_map_sizes(t_game *game)
{
	char	*line;
	t_pos	*map_sizes;

	line = ft_strnew(0);
	if (read(STDIN_FILENO, line, MAP_COORD_PREFIX_LEN) < 1 ||
		!ft_strnequ(line, MAP_COORD_PREFIX, MAP_COORD_PREFIX_LEN))
		return (NULL);
	if (game->log)
	{
		fwrite("\nMap coord prefix read:", sizeof(char), 23, game->log);
		fwrite(line, sizeof(char), ft_strlen(line), game->log);
		fwrite("\n", sizeof(char), 1, game->log);
	}
	ft_strdel(&line);
	map_sizes = (t_pos *)malloc(sizeof(t_pos));
	if (!map_sizes || !(map_sizes = read_coords(game)))
		return (NULL);
	log_map_sizes(game, map_sizes);
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

void		log_map_line(t_game *game, char *line, int lines_to_read)
{
	char	*lines_str;

	if (game->log)
	{
		lines_str = ft_llint_to_str_base(lines_to_read, 10);
		fwrite("\n", sizeof(char), 1, game->log);
		fwrite(lines_str, sizeof(char), ft_strlen(lines_str), game->log);
		fwrite(" lines left, line read: ", sizeof(char), 24, game->log);
		fwrite(line, sizeof(char), ft_strlen(line), game->log);
	}
}



int			read_start_pos(t_game *game, t_pos *map_sizes,
							t_pos **self_pos, t_pos **enemy_pos)
{
	char	*line;
	int		lines_to_read;
	int		i;

	lines_to_read = map_sizes->y + 2;
	line = ft_strnew(map_sizes->x + 5);
	while (--lines_to_read > 0)
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
		log_map_line(game, line, lines_to_read);
		ft_strclr(line);
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


int			fill_heat_map_cell(int x, int y, t_pos **self_pos,
								t_pos **enemy_pos)
{
	if ((*self_pos) && ((*self_pos)->x == x && (*self_pos)->y == y))
	{
		*self_pos = (*self_pos)->next;
		return (0);
	}
	else if ((*enemy_pos) && ((*enemy_pos)->x == x && (*enemy_pos)->y == y))
	{
		*enemy_pos = (*enemy_pos)->next;
		return (-1);
	}
	else
		return (INT_MAX);
}

/*
** https://learnc.info/c/fast_array_allocation.html
*/

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
			if (game->map->heat_map[y][x] == -1)
				calculate_heat_for_pos(x, y, game->map);
			x++;
		}
		y++;
	}
}

void		log_heat_map(t_game *game, char *message)
{
	int		x;
	int		y;
	char	*value_str;
	int		value_str_len;
	int		width;

	if (!game->log)
		return ;
	y = 0;
	fwrite(message, sizeof(char), ft_strlen(message), game->log);
	while (y < game->map->sizes->y)
	{
		x = 0;
		while (x < game->map->sizes->x)
		{
			value_str = ft_itoa(game->map->heat_map[y][x]);
			value_str_len = ft_strlen(value_str);
			width = ((5 - value_str_len) >= 0 ? 5 - value_str_len : 1);
			fwrite("      ", sizeof(char), width, game->log);
			fwrite(value_str, sizeof(char), value_str_len, game->log);
			x++;
		}
		fwrite("\n", sizeof(char), 1, game->log);
		y++;
	}
}

int			create_map(t_game *game)
{
	t_pos	*map_sizes;
	t_pos	*self_start_pos;
	t_pos	*enemy_start_pos;

	self_start_pos = NULL;
	enemy_start_pos = NULL;
	if (!(map_sizes = read_map_sizes(game)) ||
		!(read_start_pos(game, map_sizes, &self_start_pos, &enemy_start_pos)))
		return (0);
	game->map = init_map(map_sizes, self_start_pos, enemy_start_pos);
	if (!game->map)
		return (0);
	update_heat_map(game);
	log_heat_map(game, "\nHeat map created:\n");
	return (1);
}

t_piece		*init_peace(t_pos *sizes)
{
	int		**token;
	int		token_size;
	t_piece	*piece;
	int		y;

	token_size = sizeof(int *) * sizes->y + sizeof(int) * sizes->y * sizes->x;
	token = (int **)malloc(token_size);
	if (!token || !(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	y = -1;
	while (++y < sizes->y)
		token[y] = (int *)(token + sizes->y) + y * sizes->x;
	ft_memset(token + sizes->y, 0, token_size);
	piece->sizes = sizes;
	piece->token = token;
	return(piece);
}

int			is_valid_piece_line(char *line, int len)
{
	if (ft_strlen(line) != (size_t)len)
		return (0);
	while (*line)
	{
		if ((*line != PIECE_SYM) && (*line != EMPTY_SYM))
			return (0);
		line++;
	}
	return (1);
}

void		copy_line_to_token(char *line, int **token, int row)
{
	int		i;

	i = 0;
	while (line[i])
	{
		token[row][i] = (line[i] == '*' ? 1 : 0);
		i++;
	}
}

t_piece		*read_piece(t_game *game)
{
	t_pos	*sizes;
	char	*line;
	t_piece	*piece;
	int		lines_to_read;

	line = ft_strnew(0);
	if ((read(STDIN_FILENO, line, PIECE_COORD_PREFIX_LEN) < 1) ||
		(!ft_strnequ(line, PIECE_COORD_PREFIX, PIECE_COORD_PREFIX_LEN) ||
		!(sizes = read_coords(game))) ||
		!(piece = init_peace(sizes)))
		return (NULL);
	lines_to_read = sizes->y;
	line = ft_strnew(sizes->x + 1);
	while (lines_to_read > 0)
	{
		if ((read(STDIN_FILENO, line, sizes->x) < 1) ||
			!is_valid_piece_line(line, sizes->x))
			return (NULL);
		copy_line_to_token(line, piece->token, sizes->y - lines_to_read);
		lines_to_read--;
		log_map_line(game, line, lines_to_read);
		read_till_newline();
	}
	ft_strdel(&line);
	return (piece);
}

void		print_pos(t_pos *pos)
{
	char	*x;
	char	*y;

	y = ft_itoa(pos->y);
	x = ft_itoa(pos->x);
	write(STDOUT_FILENO, y, ft_strlen(y));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, x, ft_strlen(x));
	write(STDOUT_FILENO, "\n", 1);
}

int			is_valid_piece_pos(t_game *game, int x, int y)
{
	int		cell_match_flag;
	int		px;
	int		py;

	cell_match_flag = 0;
	py = -1;
	while (++py < game->self_piece->sizes->y)
	{
		px = -1;
		while (++px < game->self_piece->sizes->x)
		{
			if ((game->map->heat_map[py + y][px + x] == -1) &&
				(game->self_piece->token[py][px] == 1))
				return (0);
			if (game->self_piece->token[py][px] &&
				(game->map->heat_map[py + y][px + x] == 0))
			{
				if (cell_match_flag)
					return (0);
				else
					cell_match_flag = 1;
			}
		}
	}
	return (cell_match_flag ? 1 : 0);
}

int				calculate_sum(t_game *game, int x, int y)
{
	int			px;
	int			py;
	int			sum;

	py = 0;
	sum = 0;
	while (py < game->self_piece->sizes->y)
	{
		px = 0;
		while (px < game->self_piece->sizes->x)
		{
			sum += (game->self_piece->token[py][px] ? 
					game->map->heat_map[py + y][px + x] : 0);
			px++;
		}
		py++;
	}
	return (sum);
}

void			add_current_best_pos(t_pos **current_best, int x, int y)
{
	if (!*current_best && !(*current_best = (t_pos *)malloc(sizeof(t_pos))))
		return ;
	(*current_best)->x = x;
	(*current_best)->y = y;

}

t_pos			*find_best_positions(t_game *game)
{
	t_pos		*current_best;
	long int	min_sum;
	long int	sum;
	int			y;
	int			x;

	y = -1;
	current_best = NULL;
	min_sum = LONG_MAX;
	while (++y <= game->map->sizes->y - game->self_piece->sizes->y)
	{
		x = -1;
		while (++x <= game->map->sizes->x - game->self_piece->sizes->x)
		{
			if (is_valid_piece_pos(game, x, y) &&
				((sum = calculate_sum(game, x, y)) < min_sum))
			{
				min_sum = sum;
				add_current_best_pos(&current_best, x, y);
			}
		}
	}
	return (current_best);
}

t_pos			*choose_pos(t_game *game)
{
	// static int	flag = 1;
	t_pos		*best_pos;

	if (!(best_pos = find_best_positions(game)))
		return (NULL);
	// else if (flag == 1)
	// 	flag = -1;
	// else
	// {
	// 	flag = 1;
	// 	while (best_pos->next)
	// 		best_pos = best_pos->next;
	// }

	return (best_pos);
}

void		free_game(t_game *game)
{
	if (game->self)
		ft_memdel((void **)&game->self);
	if (game->enemy)
		ft_memdel((void **)&game->enemy);
	if (game->map)
	{
		if (game->map->heat_map)
			ft_memdel((void **)&game->map->heat_map);
		ft_memdel((void **)&game->map);
	}
	if (game->self_piece)
	{
		if (game->self_piece->token)
			ft_memdel((void **)&game->self_piece->token);
		ft_memdel((void **)&game->self_piece);
	}
	if (game->choosed_pos)
		ft_memdel((void **)&game->choosed_pos);
	if (game->log)
		fclose(game->log);
}

int			finish_game(t_game **game)
{
	free_game(*game);
	free(*game);
	*game = NULL;
	return (1);
}

void		log_choosed_pos(t_game *game)
{
	char		*x_str;
	char		*y_str;
	
	if (game->log)
	{
		x_str = ft_itoa(game->choosed_pos->x);
		y_str = ft_itoa(game->choosed_pos->y);
		fwrite("\nChoosed position is: ", sizeof(char), 22, game->log);
		fwrite(y_str, sizeof(char), ft_strlen(y_str), game->log);
		fwrite(" ", sizeof(char), 1, game->log);
		fwrite(x_str, sizeof(char), ft_strlen(x_str), game->log);
		fwrite("\n", sizeof(char), 1, game->log);
	}
}

void		add_self_pos_to_heatmap(t_game *game)
{
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;

	pos_x = game->choosed_pos->x;
	pos_y = game->choosed_pos->y;
	y = 0;
	while (y < game->self_piece->sizes->y)
	{
		x = 0;
		while (x < game->self_piece->sizes->x)
		{
			if (game->self_piece->token[y][x] == 1)
				game->map->heat_map[pos_y + y][pos_x + x] = 0;
			x++;
		}
		y++;
	}
	log_heat_map(game, "\nAdded self piece to Heat map:\n");
}

int			update_enemy_pos(t_game *game)
{
	char	*line;
	int		x;
	int		y;
	int		bytes;

	line = ft_strnew(game->map->sizes->x + X_MAP_OFFSET + 1);
	y = 0;
	read_till_newline();
	while (y < game->map->sizes->y + 1)
	{
		if ((bytes = read(STDIN_FILENO, line, game->map->sizes->x + X_MAP_OFFSET + 1))
			< 1)
			return (0);
		line[game->map->sizes->x + 4] = '\0';
		x = 4;
		while (x < game->map->sizes->x)
		{
			if (line[x] == game->enemy->latest_sym)
				game->map->heat_map[y][x - X_MAP_OFFSET] = -1;
			x++;
		}
		y++;
	}
	log_heat_map(game, "\nAdded enemy piece:\n");
	ft_strdel(&line);
	return (1);
}

int			filler(int log_flag)
{
	t_game	*game;
	char	*line;

	line = ft_strnew(2);
	game = init_game(log_flag);
	if (!game || !read_players(game) || !create_map(game))
		return (0);
	while (game)
	{
		if (!(game->self_piece = read_piece(game)))
			return (0);
		if (!(game->choosed_pos = choose_pos(game)))
			return (finish_game(&game));
		log_choosed_pos(game);
		print_pos(game->choosed_pos);
		add_self_pos_to_heatmap(game);
		// if (read(STDIN_FILENO, line, 1) > 0)
			if (!(update_enemy_pos(game)))
				return (finish_game(&game));
		update_heat_map(game);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	int		log_flag;
	(void)ac;
	(void)av;

	// FILE	*fp;
	// int		i = 0;
	// char	c = '\0';
	// char	*line = ft_strnew(1000);
	// fp = fopen("vm_input", "w");
	// while (i < 20)
	// {
	// 	get_next_line(STDIN_FILENO, &line);
	// 	fprintf(fp, "%s\n", line);
	// 	i++;
	// }
	// ft_putnbr(8);
	// ft_putchar(' ');
	// ft_putnbr(2);
	// ft_putchar('\n');
	// i = 0;
	// while (i < 19)
	// {
	// 	if (read(STDIN_FILENO, &c, 1) > 0)
	// 		get_next_line(STDIN_FILENO, &line);
	// 	fprintf(fp, "%s\n", line);
	// 	i++;
	// }
	// ft_putnbr(8);
	// ft_putchar(' ');
	// ft_putnbr(3);
	// ft_putchar('\n');
	
	// i = 0;
	// while (i < 19)
	// {
	// 	if (read(STDIN_FILENO, &c, 1) > 0)
	// 		get_next_line(STDIN_FILENO, &line);
	// 	fprintf(fp, "%s\n", line);
	// 	i++;
	// }
	// ft_putnbr(8);
	// ft_putchar(' ');
	// ft_putnbr(4);
	// ft_putchar('\n');
	// fclose(fp);

	i = 1;
	log_flag = i + 1;

	// log_flag = 0;
	// while (ac > i)
	// 	if (ft_strequ(av[i++], "-d"))
	// 		log_flag = 1;

	if (!filler(log_flag))
	{
		perror("An error occured in filler program");
		return (0);
	}
	return (0);
}
