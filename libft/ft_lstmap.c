/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:27:11 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:22:39 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del_content(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(first = f(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	tmp = first;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(ft_lstnew(lst->content, lst->content_size))))
		{
			ft_lstdel(&first, del_content);
			return (NULL);
		}
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (first);
}

/*
** ft_lstmap
** 	Prototype
** t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
** 	Description
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the suc-
** cessive applications of f. If the allocation fails, the function
** returns NULL.
** 	Param. #1
** A pointer’s to the first link of a list.
** 	Param. #2
** The address of a function to apply to each link of a list.
** 	Return value
** The new list.
** 	Libc functions
** malloc(3), free(3).
*/
