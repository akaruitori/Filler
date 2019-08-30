/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:16:52 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 14:23:04 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;

	temp = s;
	while (n--)
	{
		*temp = (unsigned char)c;
		temp++;
	}
	return (s);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        void *memset(void *s, int c, size_t n);
**
** DESCRIPTION
**        The memset() function fills the first n bytes of the memory area
** 	   pointed to by s with the
**        constant byte c.
**
** RETURN VALUE
**        The memset() function returns a pointer to the memory area s.
*/
