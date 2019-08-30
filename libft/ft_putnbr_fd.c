/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:03:34 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/23 20:28:11 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n <= 9)
	{
		n += 48;
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/*
** ft_putnbr_fd
**
** Prototype
** 	void ft_putnbr_fd(int n, int fd);
** Description
**	Outputs the integer n to the file descriptor fd.
** Param. #1
**	The integer to print.
** Param. #2
**	The file descriptor.
** Return value
**	None
** Libc functions
**	write(2).
*/
