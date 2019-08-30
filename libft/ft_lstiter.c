/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:26:30 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 13:27:55 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	}
}

/*
** ft_lstiter
** 	Prototype
** void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
** 	Description
** Iterates the list lst and applies the function f to each link.
** 	Param. #1
** A pointer to the first link of a list.
** 	Param. #2
** The address of a function to apply to each link of a list.
** 	Return value
** None.
** 	Libc functions
** None.
*/
