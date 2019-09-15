/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_choosing_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:36 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:57:25 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		log_heat_map(t_game *game, char *message)
{
	int		x;
	int		y;
	char	*value_str;
	int		value_str_len;
	int		width;

	if (!game->log)
		return ;
	y = -1;
	fwrite(message, sizeof(char), ft_strlen(message), game->log);
	while (++y < game->map->sizes->y)
	{
		x = -1;
		while (++x < game->map->sizes->x)
		{
			value_str = ft_itoa(game->map->heat_map[y][x]);
			value_str_len = ft_strlen(value_str);
			width = ((5 - value_str_len) >= 0 ? 5 - value_str_len : 1);
			fwrite("      ", sizeof(char), width, game->log);
			fwrite(value_str, sizeof(char), value_str_len, game->log);
			ft_strdel(&value_str);
		}
		fwrite("\n", sizeof(char), 1, game->log);
	}
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
		ft_strdel(&x_str);
		ft_strdel(&y_str);
	}
}
