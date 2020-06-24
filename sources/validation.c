/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:46:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:05:52 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int			is_valid_piece_pos(t_game *game, int x, int y)
{
	int		cell_match_flag;
	int		px;
	int		py;

	cell_match_flag = 0;
	py = -1;
	while (++py < game->self_piece->act_sizes->y)
	{
		px = -1;
		while (++px < game->self_piece->act_sizes->x)
		{
			if ((game->map->heat_map[py + y][px + x] == -1) &&
				(game->self_piece->token[py][px] == 1))
				return (0);
			if (game->self_piece->token[py][px] &&
				(game->map->heat_map[py + y][px + x] == 0))
				cell_match_flag++;
		}
	}
	return (cell_match_flag == 1 ? 1 : 0);
}
