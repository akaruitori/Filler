/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split_each_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 22:10:39 by dtimeon           #+#    #+#             */
/*   Updated: 2019/06/30 18:53:05 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				**ft_str_split_each_char(char *s, char c)
{
	char			**result;
	size_t			words_number;
	size_t			i;

	if (!(result = (char **)malloc(sizeof(char *) * \
									(ft_str_count_char(s, c) + 1))))
		return (NULL);
	i = -1;
	words_number = 0;
	while (*s)
	{
		i++;
		if (*s == c)
		{
			if (!(result[words_number++] = ft_strndup(s - i, i)))
			{
				ft_str_free_nonullterm_array(&result, words_number);
				return (NULL);
			}
			i = -1;
		}
		s++;
	}
	result[words_number] = NULL;
	return (result);
}
