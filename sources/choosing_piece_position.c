/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_piece_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:07:01 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:10:11 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	while (++y <= game->map->sizes->y - game->self_piece->act_sizes->y)
	{
		x = -1;
		while (++x <= game->map->sizes->x - game->self_piece->act_sizes->x)
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

int				choose_pos(t_game *game)
{
	if (game->choosed_pos)
		ft_memdel((void **)&game->choosed_pos);
	if (!save_act_piece_sizes(game->self_piece) ||
		!(game->choosed_pos = find_best_positions(game)))
		return (0);
	return (1);
}
