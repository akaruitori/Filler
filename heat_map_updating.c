/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map_updating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:15 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:11:10 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int			calculate_sum(t_game *game, int x, int y)
{
	int		px;
	int		py;
	int		sum;

	py = 0;
	sum = 0;
	while (py < game->self_piece->act_sizes->y)
	{
		px = 0;
		while (px < game->self_piece->act_sizes->x)
		{
			sum += (game->self_piece->token[py][px] ?
					game->map->heat_map[py + y][px + x] : 0);
			px++;
		}
		py++;
	}
	return (sum);
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

	y = 0;
	while (y < game->map->sizes->y + 2)
	{
		if (get_next_line(STDIN_FILENO, &line) < 1)
			return (0);
		x = X_MAP_OFFSET;
		while ((y > 1) && ((x - X_MAP_OFFSET) < game->map->sizes->x))
		{
			if (line[x] && line[x] == game->enemy->latest_sym)
				game->map->heat_map[y - 2][x - X_MAP_OFFSET] = -1;
			x++;
		}
		y++;
		ft_strdel(&line);
	}
	log_heat_map(game, "\nAdded enemy piece:\n");
	return (1);
}
