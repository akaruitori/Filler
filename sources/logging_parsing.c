/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:46:08 by dtimeon           #+#    #+#             */
/*   Updated: 2020/06/17 13:18:06 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		log_player_line(t_game *game, char *line)
{
	if (game->log)
	{
		fwrite(line, sizeof(char), ft_strlen(line), game->log);
		fwrite(" is read\n", sizeof(char), 9, game->log);
	}
}

void		log_self_no(t_game *game, int self_no)
{
	char	*self_no_str;

	if (game->log)
	{
		self_no_str = ft_llint_to_str_base(self_no, 10);
		fwrite("Player no is ", sizeof(char), 13, game->log);
		fwrite(self_no_str, sizeof(char), ft_strlen(self_no_str), game->log);
		fwrite("\n", sizeof(char), 1, game->log);
		ft_strdel(&self_no_str);
	}
}

void		log_players_creation(t_game *game)
{
	if (game->log)
	{
		fwrite("\nPlayers are created\n", sizeof(char), 21, game->log);
	}
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
		ft_strdel(&x);
		ft_strdel(&y);
	}
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
		ft_strdel(&lines_str);
	}
}
