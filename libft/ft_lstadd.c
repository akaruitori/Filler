/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:25:09 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 13:26:27 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = (alst && *alst) ? *alst : NULL;
		*alst = new;
	}
}

/*
** ft_lstadd
** 	Prototype
** void ft_lstadd(t_list **alst, t_list *new);
** 	Description
** Adds the element new at the beginning of the list.
** 	Param. #1
** The address of a pointer to the first link of a list.
** 	Param. #2
** The link to add at the beginning of the list.
** 	Return value
** None.
** 	Libc functions
** None.
*/
