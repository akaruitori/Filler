/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:29:27 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 17:01:24 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(size)))
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}

/*
** ft_strnew
**
** Prototype
** 	char * ft_strnew(size_t size);
** Description
**	Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
**	Each character of the string is initialized at ’\0’. If the allocation
**	fails the function returns NULL.
** Param. #1
**	The size of the string to be allocated.
** Return value
**	The string allocated and initialized to 0.
** Libc functions
**	malloc(3)
*/
