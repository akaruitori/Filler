/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:45:51 by dtimeon           #+#    #+#             */
/*   Updated: 2019/05/24 11:38:05 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	char	*temp_dest;

	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	temp_dest = dest;
	while (*src && n--)
	{
		*temp_dest = *src;
		temp_dest++;
		src++;
	}
	*temp_dest = '\0';
	return (dest);
}
