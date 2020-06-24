/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map_creating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:07 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:01:32 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	ft_memdel((void **)&self_start_pos);
	free_enemy_start_pos(&enemy_start_pos);
	if (!game->map)
		return (0);
	update_heat_map(game);
	log_heat_map(game, "\nHeat map created:\n");
	return (1);
}
