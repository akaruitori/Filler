/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:54 by dtimeon           #+#    #+#             */
/*   Updated: 2019/09/15 17:16:26 by dtimeon          ###   ########.fr       */
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

# define PLAYER_EXEC_START "$$$ exec p"
# define PLAYER_EXEC_START_LEN 10
# define PLAYER_EXEC_LEN 11
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
# define EMPTY_SYM '.'
# define PIECE_SYM '*'
# define LOG_FILENAME "log.txt"

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
	t_pos			*sizes;
	t_pos			*act_sizes;
	int				**token;
}					t_piece;

typedef struct		s_game
{
	t_player		*self;
	t_player		*enemy;
	t_map			*map;
	t_piece			*self_piece;
	t_pos			*choosed_pos;
	FILE			*log;
}					t_game;

/*
**  parcing_player
*/
char				*find_player_line(t_game *game);
int					read_player_no(char *line);
int					read_players(t_game *game);

/*
**  parcing_map_and_piece
*/
t_pos				*read_coords(char *line);
t_pos				*read_map_sizes(t_game *game);
int					read_start_pos(t_game *game, t_pos *map_sizes,
									t_pos **self_pos, t_pos **enemy_pos);
t_pos				*read_coords_line();
int					read_piece(t_game *game);

/*
** initialization
*/
t_player			*init_player(int player_no);
t_game				*init_game();
t_map				*init_map(t_pos *map_sizes,
								t_pos *self_start_pos,
								t_pos *enemy_start_pos);
t_piece				*init_peace(t_pos *sizes);

/*
** saving_game_data
*/
int					save_players(t_game *game, char *line);
void				save_start_pos(t_pos **player_pos, int x, int y);
void				copy_line_to_token(char *line, int **token, int row);
int					save_act_piece_sizes(t_piece *piece);

/*
** heat_map_creating
*/
int					fill_heat_map_cell(int x, int y, t_pos **self_pos,
										t_pos **enemy_pos);
int					**create_heat_map(t_pos *map_sizes, t_pos *self_pos,
										t_pos *enemy_pos);
void				update_heat_map(t_game *game);
int					create_map(t_game *game);

/*
** heat_map_updating
*/
void				calculate_heat_for_pos(int enemy_x, int enemy_y,
											t_map *map);
int					calculate_sum(t_game *game, int x, int y);
void				add_self_pos_to_heatmap(t_game *game);
int					update_enemy_pos(t_game *game);

/*
** validation
*/
int					is_valid_piece_line(char *line, int len);
int					is_valid_piece_pos(t_game *game, int x, int y);


/*
** logging_parcing
*/
void				log_player_line(t_game *game, char *line);
void				log_self_no(t_game *game, int self_no);
void				log_players_creation(t_game *game);
void				log_map_sizes(t_game *game, t_pos *map_sizes);
void				log_map_line(t_game *game, char *line, int lines_to_read);

/*
** logging_choosing_pos
*/
void				log_heat_map(t_game *game, char *message);
void				log_choosed_pos(t_game *game);

/*
** max_and_min
*/
int					ft_max(int a, int b);
int					ft_min(int a, int b);

/*
** choosing_piece_position
*/
void				add_current_best_pos(t_pos **current_best, int x, int y);
t_pos				*find_best_positions(t_game *game);
int					choose_pos(t_game *game);

/*
** freeing
*/
void				free_enemy_start_pos(t_pos **enemy_pos);
void				free_piece(t_piece **piece);
void				free_game(t_game *game);

#endif
