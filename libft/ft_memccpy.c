/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:05:23 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/25 21:03:03 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		*temp_dest = *temp_src;
		if (*temp_src == (unsigned char)c)
			return (++temp_dest);
		temp_dest++;
		temp_src++;
		n--;
	}
	return (NULL);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        void *memccpy(void *dest, const void *src, int c, size_t n);
**
** DESCRIPTION
**        The  memccpy()  function  copies  no more than n bytes from
**        memory area src to memory  area  dest,  stopping  when  the
**        character c is found.
**
**        If the memory areas overlap, the results are undefined.
**
** RETURN VALUE
**        The  memccpy() function returns a pointer to the next char‐
**        acter in dest after c, or NULL if c was not  found  in  the
**        first n characters of src.
*/
