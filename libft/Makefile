NAME = libft.a

SOURCE =	ft_bzero.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strcat.c ft_strcmp.c \
			ft_strncmp.c ft_strcpy.c ft_strdup.c \
			ft_strlcat.c ft_strlen.c ft_strchr.c \
			ft_strnstr.c ft_strstr.c ft_strncat.c \
			ft_strncpy.c ft_isspace.c ft_strnchr.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_isspace.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c \
			ft_atoi.c ft_itoa.c ft_putchar_fd.c \
			ft_putchar.c ft_putstr_fd.c ft_putstr.c \
			ft_memalloc.c ft_memdel.c ft_putendl_fd.c \
			ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
			ft_strclr.c ft_strdel.c ft_strequ.c \
			ft_strnequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strmap.c ft_strmapi.c \
			ft_strnew.c ft_strsplit.c ft_strsub.c \
			ft_strtrim.c ft_lstadd.c ft_lstdel.c \
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c ft_chrtoint.c ft_strnchr.c \
			ft_strtol.c ft_abs.c ft_lstfind.c \
			ft_lstcount.c ft_putunichar_fd.c ft_putunistr_fd.c \
			ft_list_push_front.c ft_list_push_back.c ft_strndup.c \
			ft_lst_del_content.c ft_str_free_array.c ft_str_count_char.c \
			ft_str_split_each_char.c ft_str_free_nonullterm_array.c \
			get_next_line.c ft_llint_to_str_base.c ft_ullint_to_str_base.c

INC_DIR = ./

OBJECTS_DIR = ./objects/

OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECT_FILE))

OBJECT_FILE = $(SOURCE:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS_DIR)%.o: %.c $(INC_DIR)libft.h
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir $(OBJECTS_DIR)

clean:
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -fr $(OBJECTS_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
