/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving_game_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:46:27 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:57:59 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			save_players(t_game *game, char *line)
{
	int		self_no;

	self_no = read_player_no(line);
	log_self_no(game, self_no);
	if (self_no != 1 && self_no != 2)
		return (0);
	game->self = init_player(self_no);
	game->enemy = init_player(self_no == 1 ? 2 : 1);
	if (!game->self || !game->enemy)
		return (0);
	log_players_creation(game);
	return (1);
}

void		save_start_pos(t_pos **player_pos, int x, int y)
{
	t_pos	*new;
	t_pos	*temp;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		return ;
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (*player_pos)
	{
		temp = *player_pos;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*player_pos = new;
}

void		copy_line_to_token(char *line, int **token, int row)
{
	int		i;

	i = 0;
	while (line[i])
	{
		token[row][i] = (line[i] == '*' ? 1 : 0);
		i++;
	}
}

int			save_act_piece_sizes(t_piece *piece)
{
	int		x;
	int		y;

	piece->act_sizes->x = 0;
	piece->act_sizes->y = 0;
	y = 0;
	while (y < piece->sizes->y)
	{
		x = 0;
		while (x < piece->sizes->x)
		{
			if (piece->token[y][x] == 1)
			{
				piece->act_sizes->x = ft_max(piece->act_sizes->x, x + 1);
				piece->act_sizes->y = ft_max(piece->act_sizes->y, y + 1);
			}
			x++;
		}
		y++;
	}
	return (piece->act_sizes->x && piece->act_sizes->y);
}
