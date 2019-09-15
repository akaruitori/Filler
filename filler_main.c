/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:52:29 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	ft_strdel(&x);
	ft_strdel(&y);
}

int			finish_game(t_game **game)
{
	free_game(*game);
	free(*game);
	*game = NULL;
	return (1);
}

int			filler(void)
{
	t_game	*game;

	game = init_game();
	if (!game || !read_players(game) || !create_map(game))
	{
		finish_game(&game);
		return (0);
	}
	while (game)
	{
		if (!(read_piece(game)))
		{
			finish_game(&game);
			return (0);
		}
		if (!choose_pos(game))
			return (finish_game(&game));
		log_choosed_pos(game);
		print_pos(game->choosed_pos);
		add_self_pos_to_heatmap(game);
		if (!(update_enemy_pos(game)))
			return (finish_game(&game));
		update_heat_map(game);
	}
	return (1);
}

int			main(void)
{
	filler();
	return (0);
}
