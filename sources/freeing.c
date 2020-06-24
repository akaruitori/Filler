/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:44:48 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:37:31 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_enemy_start_pos(t_pos **enemy_pos)
{
	t_pos	*temp1;
	t_pos	*temp2;

	temp1 = (*enemy_pos)->next;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		ft_memdel((void **)&temp2);
	}
	ft_memdel((void **)enemy_pos);
}

void		free_piece(t_piece **piece)
{
	if ((*piece)->token)
		ft_memdel((void **)&(*piece)->token);
	if ((*piece)->act_sizes)
		ft_memdel((void **)&(*piece)->act_sizes);
	if ((*piece)->sizes)
		ft_memdel((void **)&(*piece)->sizes);
	ft_memdel((void **)piece);
}

void		free_game(t_game *game)
{
	if (game->self)
		ft_memdel((void **)&game->self);
	if (game->enemy)
	{
		if (game->enemy->start_pos)
			free_enemy_start_pos(&game->enemy->start_pos);
		ft_memdel((void **)&game->enemy);
	}
	if (game->map)
	{
		if (game->map->heat_map)
			ft_memdel((void **)&game->map->heat_map);
		if (game->map->sizes)
			ft_memdel((void **)&game->map->sizes);
		ft_memdel((void **)&game->map);
	}
	if (game->self_piece)
		free_piece(&game->self_piece);
	if (game->choosed_pos)
		ft_memdel((void **)&game->choosed_pos);
	if (game->log)
		fclose(game->log);
}
