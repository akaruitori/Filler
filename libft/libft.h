/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:05:45 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/30 20:44:03 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 32

typedef struct		s_flist
{
	int				fd;
	char			*buf;
	struct s_flist	*next;
	struct s_flist	*prev;
}					t_flist;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_chrtoint(char c);
long long int		ft_abs(long long int n);
char				*ft_strnchr(const char *str, char c, size_t n);
long int			ft_strtol(const char *nptr, char **endptr, int base);
size_t				ft_lstcount(t_list *list);
t_list				*ft_lstfind(t_list *list, int (*f)(t_list *elem));
void				ft_putunichar_fd(int c, int fd);
void				ft_putunistr_fd(char *s, int fd);
void				ft_list_push_front(t_list **begin, void *d, size_t d_size);
int					ft_list_push_back(t_list **begin, void *d, size_t d_size);
char				*ft_strndup(const char *s, size_t n);
void				ft_lst_del_content(void *content, size_t size);
void				ft_str_free_array(char ***array);
void				ft_str_free_nonullterm_array(char ***array, size_t size);
size_t				ft_str_count_char(char *s, char c);
char				**ft_str_split_each_char(char *s, char c);
char				*ft_llint_to_str_base(long long int n, int base);
char				*ft_ullint_to_str_base(unsigned long long int n, int base);

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
