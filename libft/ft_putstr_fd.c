/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:04:11 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/25 22:32:41 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}

/*
** ft_putstr_fd
**
** Prototype
** 	void ft_putstr_fd(char const *s, int fd);
** Description
**	Outputs the string s to the file descriptor fd.
** Param. #1
**	The string to output.
** Param. #2
**	The file descriptor.
** Return value
**	None
** Libc functions
**	write(2).
*/
