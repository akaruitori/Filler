/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:54 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/05 17:43:44 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define PLAYER_EXEC_START "$$$"
# define PLAYER_EXEC_START_LEN 3
# define PLAYER_NO_POS 10
# define PLAYER1_SYM 'O'
# define PLAYER1_LATEST_SYM 'o'
# define PLAYER2_SYM 'X'
# define PLAYER2_LATEST_SYM 'x'
# define MAP_COORD_PREFIX "Plateau "
# define MAP_COORD_PREFIX_LEN 8
# define PIECE_COORD_PREFIX "Piece "
# define PIECE_COORD_PREFIX_LEN 6
# define X_MAP_OFFSET 4

typedef struct		s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
}					t_pos;

typedef struct		s_player
{
	// char			*name;
	char			sym;
	char			latest_sym;
	t_pos			*start_pos;
}					t_player;

typedef struct		s_map
{
	int				**heat_map;
	t_pos			*sizes;
}					t_map;

typedef struct		s_piece
{
	int				width;
	int				height;
	char			**token;
}					t_piece;

typedef struct		s_game
{
	t_player		*self;
	t_player		*enemy;
	t_map			*map;
}					t_game;

#endif
