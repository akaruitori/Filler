/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:20:34 by dtimeon           #+#    #+#             */
/*   Updated: 2019/06/30 18:12:10 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (as || *as)
	{
		free(*as);
		*as = NULL;
	}
}

/*
** ft_strdel
**
** Prototype
** 	void ft_strdel(char **as);
** Description
**	Takes as a parameter the address of a string that need to be freed with
**	free(3), then sets its pointer to NULL.
** Param. #1
**	The string’s address that needs to be freed and its pointer set to NULL.
** Return value
**	None
** Libc functions
**	Free(3).
*/
