/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:45:59 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 16:57:20 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int			read_player_no(char *line)
{
	return (ft_atoi(line + PLAYER_NO_POS));
}

char		*find_player_line(t_game *game)
{
	char	*line;
	size_t	bytes_read;

	if ((bytes_read = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (ft_strnequ(line, PLAYER_EXEC_START, PLAYER_EXEC_START_LEN))
		{
			log_player_line(game, line);
			return (line);
		}
		ft_strdel(&line);
	}
	return (NULL);
}
