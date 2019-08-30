/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:21:51 by dtimeon           #+#    #+#             */
/*   Updated: 2019/05/08 00:20:46 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data, size_t data_size)
{
	t_list	*new_list;

	if (*begin_list)
	{
		new_list = ft_lstnew(data, data_size);
		new_list->next = *begin_list;
		*begin_list = new_list;
	}
	else
		*begin_list = ft_lstnew(data, data_size);
}
