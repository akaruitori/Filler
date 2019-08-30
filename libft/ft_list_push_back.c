/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:39:17 by dtimeon           #+#    #+#             */
/*   Updated: 2019/05/24 16:14:54 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_list_push_back(t_list **begin_list, void *data, size_t data_size)
{
	t_list	*new_list;

	if (!begin_list)
		return (0);
	new_list = *begin_list;
	if (new_list)
	{
		while (new_list->next)
			new_list = new_list->next;
		if (!(new_list->next = ft_lstnew(data, data_size)))
			return (0);
	}
	else
	{
		if (!(*begin_list = ft_lstnew(data, data_size)))
			return (0);
	}
	return (1);
}
