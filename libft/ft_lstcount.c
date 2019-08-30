/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:09:51 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/25 21:13:00 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcount(t_list *list)
{
	size_t	result;

	result = 0;
	while (list)
	{
		result++;
		list = list->next;
	}
	return (result);
}
