/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:03:12 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:51:54 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}

/*
** ft_putendl_fd
**
** Prototype
** 	void ft_putendl_fd(char const *s, int fd);
** Description
**	Outputs the string s to the file descriptor fd followed by a ’\n’.
** Param. #1
**	The string to output.
** Param. #2
**	The file descriptor.
** Return value
**	None
** Libc functions
**	write(2).
*/
