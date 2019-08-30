/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:25:25 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 17:02:17 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && del)
	{
		temp = *alst;
		while (temp)
		{
			del(temp->content, temp->content_size);
			free(temp);
			temp = temp->next;
		}
		*alst = NULL;
	}
}

/*
** ft_lstdel
** 	Prototype
** void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
** 	Description
** Takes as a parameter the adress of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions del and free(3). Finally the pointer to
** the link that was just freed must be set to NULL (quite similar
** to the function ft_memdel from the mandatory part).
** 	Param. #1
** The address of a pointer to the first link of a list that needs
** to be freed.
** 	Return value
** None.
** 	Libc functions
** free(3)
*/
