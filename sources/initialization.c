/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:24 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:57:09 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player		*init_player(int player_no)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->sym = (player_no == 1 ? 'O' : 'X');
	new->latest_sym = (player_no == 1 ? 'o' : 'x');
	new->start_pos = NULL;
	return (new);
}

t_game			*init_game(void)
{
	t_game		*new;

	if (!(new = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	new->map = NULL;
	new->self = NULL;
	new->enemy = NULL;
	new->self_piece = NULL;
	new->choosed_pos = NULL;
	if (!(new->log = fopen(LOG_FILENAME, "w")))
		new->log = NULL;
	fwrite("Game struct initialized\n", sizeof(char), 24, new->log);
	return (new);
}

t_map			*init_map(t_pos *map_sizes, t_pos *self_start_pos,
						t_pos *enemy_start_pos)
{
	t_map		*new;
	int			**heat_map;

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

t_piece			*init_peace(t_pos *sizes)
{
	int			token_size;
	t_piece		*piece;
	int			y;

	token_size = sizeof(int *) * sizes->y + sizeof(int) * sizes->y * sizes->x;
	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	if (!(piece->token = (int **)malloc(token_size)))
	{
		ft_memdel((void **)&piece);
		return (NULL);
	}
	piece->token[0] = (int *)(piece->token + sizes->y);
	y = 0;
	while (++y < sizes->y)
		piece->token[y] = piece->token[0] + y * sizes->x;
	piece->sizes = sizes;
	piece->act_sizes = (t_pos *)malloc(sizeof(t_pos));
	if (!piece->act_sizes)
	{
		ft_memdel((void **)&piece->token);
		ft_memdel((void **)&piece);
		return (NULL);
	}
	return (piece);
}
