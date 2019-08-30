/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:32:45 by dtimeon           #+#    #+#             */
/*   Updated: 2019/06/30 18:40:04 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flist		*add_flist(int fd, char *buf, t_flist *next, t_flist *prev)
{
	t_flist			*file;

	if ((file = (t_flist *)malloc(sizeof(t_flist))))
	{
		file->fd = fd;
		file->next = next;
		file->prev = prev;
		file->buf = buf;
	}
	return (file);
}

static int			update_buf(int fd, char **buffer)
{
	char			*buf_tmp;
	char			*buf_to_free;
	ssize_t			bytes_read;

	if (!(buf_tmp = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((bytes_read = read(fd, buf_tmp, BUFF_SIZE)) > 0)
	{
		buf_tmp[bytes_read] = '\0';
		buf_to_free = *buffer;
		*buffer = ft_strjoin(*buffer, buf_tmp);
		free(buf_to_free);
		if (!(*buffer))
			return (-1);
		if (ft_strchr(*buffer, '\n'))
		{
			free(buf_tmp);
			return (1);
		}
	}
	free(buf_tmp);
	if (bytes_read > 0)
		return (1);
	return (bytes_read == 0 ? 0 : -1);
}

static t_flist		*get_file(t_flist **head, int fd)
{
	t_flist			*f_temp;
	t_flist			*f_new;
	t_flist			*f_search;
	char			*buf;

	f_temp = *head;
	f_search = *head;
	while (f_search->next)
	{
		if (f_search->fd == fd)
			return (f_search);
		f_search = (f_search)->next;
	}
	if (!(buf = ft_strnew(1)) || (update_buf(fd, &buf) < 0))
		return (NULL);
	f_new = add_flist(fd, buf, f_temp, NULL);
	f_temp->prev = f_new;
	*head = f_new;
	return (f_new);
}

static int			update_line(t_flist *file, char **line)
{
	int				i;
	size_t			line_len;
	char			*buf_to_free;
	char			*line_end_pos;

	if (!(line_end_pos = ft_strchr(file->buf, '\n')))
	{
		if ((i = update_buf(file->fd, &(file->buf)) < 0))
			return (-1);
		if (!file->buf[0])
			return (0);
		if (!(line_end_pos = ft_strchr(file->buf, '\n')))
		{
			if ((*line = ft_strdup(file->buf)))
				ft_bzero(file->buf, ft_strlen(file->buf));
			return ((*line) ? 1 : -1);
		}
	}
	line_len = line_end_pos - file->buf;
	if (!(*line = ft_strndup(file->buf, line_len)))
		return (-1);
	buf_to_free = file->buf;
	file->buf = ft_strdup(line_end_pos + 1);
	free(buf_to_free);
	return (file->buf ? 1 : -1);
}

int					get_next_line(int fd, char **line)
{
	static t_flist	*files;
	t_flist			*current_file;
	int				result;

	if (read(fd, NULL, 0) < 0 || !line)
		return (-1);
	if (!files)
		if (!(files = add_flist(-1, NULL, NULL, NULL)))
			return (-1);
	if (!(current_file = get_file(&files, fd)) || (!current_file->buf))
		return (-1);
	result = update_line(current_file, line);
	if (result == 0)
	{
		ft_memdel((void **)&(current_file->buf));
		if (current_file->prev)
			current_file->prev->next = current_file->next;
		else
			files = current_file->next;
		ft_memdel((void **)&current_file);
		if (files->fd == -1)
			ft_memdel((void **)&files);
	}
	return (result);
}
