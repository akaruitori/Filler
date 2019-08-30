/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:34:40 by dtimeon           #+#    #+#             */
/*   Updated: 2019/05/24 11:37:18 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_str_count_char(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s++ == c)
			count++;
	}
	return (count);
}
