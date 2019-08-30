/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:54:40 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 00:40:31 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n--)
	{
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
	}
	return (dest);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        void *memcpy(void *dest, const void *src, size_t n);
**
** DESCRIPTION
**        The  memcpy()  function copies n bytes from memory area src
**        to memory area dest.  The memory areas  must  not  overlap.
**        Use memmove(3) if the memory areas do overlap.
**
** RETURN VALUE
**        The memcpy() function returns a pointer to dest.
**
** NOTES
**        Failure to observe the requirement that the memory areas do
**        not  overlap  has been the source of real bugs.  (POSIX and
**        the C standards are explicit that employing  memcpy()  with
**        overlapping   areas  produces  undefined  behavior.)   Most
**        notably, in glibc 2.13 a performance optimization  of  mem‐
**        cpy()  on some platforms (including x86-64) included chang‐
**        ing the order in which bytes were copied from src to dest.
**
**        This change revealed breakages in a number of  applications
**        that  performed  copying with overlapping areas.  Under the
**        previous implementation, the order in which the bytes  were
**        copied  had fortuitously hidden the bug, which was revealed
**        when the copying order was reversed.  In glibc 2.14, a ver‐
**        sioned  symbol  was added so that old binaries (i.e., those
**        linked against glibc versions earlier than 2.14) employed a
**        memcpy() implementation that safely handles the overlapping
**        buffers case (by providing an "older" memcpy()  implementa‐
**        tion that was aliased to memmove(3)).
*/
