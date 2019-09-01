/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:54 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/01 20:05:31 by dtimeon          ###   ########.fr       */
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

typedef struct		s_player
{
	char			*name;
	char			sym;
	char			latest_sym;
}					t_player;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_map
{
	int				**heat_map;
	int				width;
	int				height;
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
