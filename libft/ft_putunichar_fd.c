/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:25:19 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:16:14 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunichar_fd(int c, int fd)
{
	if (c < 128)
		ft_putchar_fd(c, fd);
	else if (c < 2048)
	{
		ft_putchar_fd(0xC0 | c >> 6, fd);
		ft_putchar_fd(0x80 | (c & 0x3F), fd);
	}
	else if (c < 65536)
	{
		ft_putchar_fd(0xE0 | c >> 12, fd);
		ft_putchar_fd(0x80 | (c >> 6 & 0x3F), fd);
		ft_putchar_fd(0x80 | (c & 0x3F), fd);
	}
	else if (c < 2097152)
	{
		ft_putchar_fd(0xF0 | c >> 18, fd);
		ft_putchar_fd(0x80 | (c >> 12 & 0x3F), fd);
		ft_putchar_fd(0x80 | (c >> 6 & 0x3F), fd);
		ft_putchar_fd(0x80 | (c & 0x3F), fd);
	}
}
