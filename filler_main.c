/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/01 20:44:13 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*find_player_line()
{
	char	*line;

	line = NULL;
	while(get_next_line(STDIN_FILENO, &line))
	{
		if (strnequ(line, "$$$", 3))
			return (line);
		ft_strdel(&line);
	}
	return (NULL);
}

int			save_player(t_game *game, char *line, char *self_name)
{
	char	*name_start;
	char	*name_end;
	int		player_no;

	player_no = read_player_no(line);
	if (!(name_start = ft_strchr(line, '[') ||
		!(name_end = ft_strchr(name_start, ']'))))
		return (0);
	if (ft_strstr(name_start, self_name) && !(game->self))
	{
		game->self = init_self(name_start, name_end - name_start, player_no);
	}
	else
	{
		game->enemy = init_enemy(name_start, name_end - name_start, player_no);
	}

}

int			read_players(t_game *game, char *self_name)
{
	char	*line;
	int		players_read;

	players_read = 0;
	while (players_read < 2)
	{
		if (!(line = find_player_line()) ||
			!(save_player(game, line, self_name)))
			return (0);
		players_read++;
	}
	return (1);
}

t_game		*init_game()
{
	t_game	*new;

	if (!(new = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	new->map = NULL;
	new->self = NULL;
	new->enemy = NULL;
	return (new);
}

int			filler(char	*self_name)
{
	t_game	*game;

	game = init_game();
	if (!game || !read_players(game, self_name))
		return (0);

	return (1);
}

int			main(int ac, char **av)
{
	if (!filler(av[0]))
	{
		perror("An error occured in filler function.");
		return (1);
	}
	return (0);
}
