/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map_and_piece.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:51 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:59:42 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos		*read_coords(char *line)
{
	int		x;
	int		y;
	t_pos	*coords;

	if (!(y = (int)ft_strtol(line, &line, 10)) ||
		!(x = (int)ft_strtol(line, NULL, 10)) ||
		(y <= 0 || x <= 0))
		return (NULL);
	coords = (t_pos *)malloc(sizeof(t_pos));
	if (!coords)
		return (NULL);
	coords->x = x;
	coords->y = y;
	return (coords);
}

t_pos		*read_map_sizes(t_game *game)
{
	char	*line;
	t_pos	*map_sizes;

	if (get_next_line(STDIN_FILENO, &line) < 1 ||
		!ft_strnequ(line, MAP_COORD_PREFIX, MAP_COORD_PREFIX_LEN))
		return (NULL);
	if (!(map_sizes = read_coords(line + MAP_COORD_PREFIX_LEN)))
		return (NULL);
	ft_strdel(&line);
	log_map_sizes(game, map_sizes);
	return (map_sizes);
}

int			read_start_pos(t_game *game, t_pos *map_sizes,
							t_pos **self_pos, t_pos **enemy_pos)
{
	char	*line;
	int		lines_to_read;
	int		i;

	lines_to_read = map_sizes->y + 2;
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
		ft_strdel(&line);
	}
	return ((!*self_pos || !*enemy_pos) ? 0 : 1);
}

t_pos		*read_coords_line(void)
{
	char	*line;
	t_pos	*sizes;

	if (get_next_line(STDIN_FILENO, &line) < 1)
		return (NULL);
	if (!ft_strnequ(line, PIECE_COORD_PREFIX, PIECE_COORD_PREFIX_LEN) ||
		!(sizes = read_coords(line + PIECE_COORD_PREFIX_LEN)))
	{
		ft_strdel(&line);
		return (NULL);
	}
	ft_strdel(&line);
	return (sizes);
}

int			read_piece(t_game *game)
{
	t_pos	*sizes;
	char	*line;
	int		lines_to_read;

	if (!(sizes = read_coords_line()))
		return (0);
	if (game->self_piece)
		free_piece(&game->self_piece);
	if (!(game->self_piece = init_peace(sizes)))
		return (0);
	lines_to_read = sizes->y;
	while (lines_to_read > 0)
	{
		if ((get_next_line(STDIN_FILENO, &line) < 1) ||
			!is_valid_piece_line(line, sizes->x))
			return (0);
		copy_line_to_token(line, game->self_piece->token,
							sizes->y - lines_to_read);
		lines_to_read--;
		log_map_line(game, line, lines_to_read);
		ft_strdel(&line);
	}
	return (1);
}
