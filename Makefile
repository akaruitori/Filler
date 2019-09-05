NAME = dtimeon.filler

LNAM = ./src/libft/libft.a

LIBF = ./libft

INCL = .

OBJECTS_DIR = ./objects/

OBJECT_FILE = $(SRCS:.c=.o)

OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECT_FILE))

SRCS = filler_main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@make -C $(LIBF) re
	$(CC) -L $(LIBF) -lft -g $(OBJECTS) -I $(INCL) -I $(LIBF) -o $(NAME)

$(OBJECTS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBF) -g -c $< -o $@

$(OBJECTS_DIR):
	@mkdir $(OBJECTS_DIR)

clean:
	@make -C $(LIBF) clean
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -fr $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBF) fclean

re: fclean all