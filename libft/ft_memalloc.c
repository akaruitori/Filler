/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:27:40 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/28 16:09:51 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*area;

	if (!(area = malloc(size)))
		return (NULL);
	ft_bzero(area, size);
	return (area);
}

/*
** ft_memalloc
**
** Prototype
** 	void *  ft_memalloc(size_t size);
** Description
** 	Allocates (with malloc(3)) and returns a “fresh” memoryarea.
** 	The memory allocated is initialized to 0. If the allocation fails,
** 	the function returns NULL.
** Param. #1
**	The size of the memory that needs
** 	to be allocated.
** Return value
** 	The allocated memory area.
** Libc functions
** 	malloc(3)
*/
