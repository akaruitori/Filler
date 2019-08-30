/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:08:52 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:22:52 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*memcpy_in_reverse(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest + n - 1;
	temp_src = (unsigned char *)src + n - 1;
	while (n--)
	{
		*temp_dest = *temp_src;
		temp_dest--;
		temp_src--;
	}
	return (dest);
}

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	else
		return (memcpy_in_reverse(dest, src, n));
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        void *memmove(void *dest, const void *src, size_t n);
**
** DESCRIPTION
**        The  memmove() function copies n bytes from memory area src
**        to memory area dest.  The memory areas may overlap: copying
**        takes  place  as  though  the bytes in src are first copied
**        into a temporary array that does not overlap src  or  dest,
**        and  the  bytes are then copied from the temporary array to
**        dest.
**
** RETURN VALUE
**        The memmove() function returns a pointer to dest.
*/
