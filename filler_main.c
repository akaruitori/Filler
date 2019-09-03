/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/03 14:49:59 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** player.write_to_player("$$$ exec p#{i} : [#{player.file_name}]\n")
*/

char		*find_player_line()
{
	char	*line;

	line = NULL;
	while(get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strnequ(line, PLAYER_EXEC_START, PLAYER_EXEC_START_LEN))
			return (line);
		ft_strdel(&line);
	}
	return (NULL);
}

int				read_player_no(char *line)
{
	return (ft_atoi(line + PLAYER_NO_POS));
}

t_player		*init_player(int player_no)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->sym = (player_no == 1 ? 'O' : 'X');
	new->latest_sym = (player_no == 1 ? 'o' : 'x');
	return (new);
}

int			save_players(t_game *game, char *line)
{
	int		self_no;

	self_no = read_player_no(line);
	if (self_no != 1 && self_no != 2)
		return (0);
	game->self = init_player(self_no);
	game->enemy = init_player(self_no == 1 ? 2 : 1);
	if (!game->self || !game->enemy)
		return (0);
	return (1);
}

int			read_players(t_game *game)
{
	char	*line;

	if (!(line = find_player_line()) ||
		!(save_players(game, line)))
		return (0);
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

int			filler()
{
	t_game	*game;

	game = init_game();
	if (!game || !read_players(game))
		return (0);

	return (1);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (!filler())
	{
		perror("An error occured in filler function");
		return (1);
	}
	return (0);
}
