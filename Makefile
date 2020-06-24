NAME = dtimeon.filler

LIBNAME= ./src/libft/libft.a

LIB_DIR = ./libft

INC_DIR = ./

INC_FILE = $(INC_DIR)filler.h

SRCS_DIR = sources/

SRC_FILES =	filler_main.c parsing_player.c parsing_map_and_piece.c \
		initialization.c saving_game_data.c heat_map_creating.c \
		heat_map_updating.c validation.c logging_parsing.c \
		logging_choosing_pos.c max_and_min.c choosing_piece_position.c \
		freeing.c

SOURCES = $(addprefix $(SRCS_DIR), $(SRC_FILES))

OBJECTS_DIR = objects/

OBJECT_FILES = $(patsubst %.c, $(OBJECTS_DIR)%.o, $(SRC_FILES))

OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECT_FILES))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECT_FILES)
	@make -C $(LIB_DIR) re
	$(CC) -L $(LIB_DIR) -lft $(OBJECT_FILES) -I $(INC_DIR) -I $(LIB_DIR) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SRCS_DIR)%.c $(INC_FILE)
	$(CC) $(CFLAGS) -I $(LIB_DIR) -I $(INC_DIR) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir $(OBJECTS_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@/bin/rm -f $(OBJECT_FILES)
	@/bin/rm -fr $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re
