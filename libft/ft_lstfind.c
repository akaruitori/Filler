/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:25:03 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/25 22:09:38 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfind(t_list *list, int (*f)(t_list *elem))
{
	t_list	*founded;

	founded = NULL;
	if (list && f)
	{
		while (list)
		{
			if (f(list))
				return (founded = list);
			list = list->next;
		}
	}
	return (NULL);
}

/*
** Searches through list applying function f to each link. Returns
** the first element such as f(list) != 0.
*/
