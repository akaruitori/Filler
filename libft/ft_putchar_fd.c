/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:02:53 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 14:02:59 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
** ft_putchar_fd
**
** Prototype
** 	void ft_putchar_fd(char c, int fd);
** Description
**	Outputs the char c to the file descriptor fd.
** Param. #1
**	The character to output.
** Param. #2
**	The file descriptor.
** Return value
**	None
** Libc functions
**	write(2).
*/
