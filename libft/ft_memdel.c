/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:32:25 by dtimeon           #+#    #+#             */
/*   Updated: 2019/06/30 19:55:59 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap || *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

/*
** ft_memdel
**
** Prototype
** 	void  ft_memdel(void **ap);
** Description
** 	Takes as a parameter the address of a memory area that needs
** 	to be freed with free(3), then puts the pointer to NULL.
** Param. #1
** 	A pointer’s address that needs its memory freed and set to NULL
** Return value
** 	None.
** Libc functions
** free(3)
*/
