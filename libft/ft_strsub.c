/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:31:18 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:25:42 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
** ft_strsub
**
** Prototype
** 	char * ft_strsub(char const *s, unsigned int start, size_t len);
** Description
**	Allocates (with malloc(3)) and returns a “fresh” substring from the string
**	given as argument. The substring begins at indexstart and is of size len.
**	If start and len aren’t refering to a valid substring, the behavior
**	is undefined. If the allocation fails, the function returns NULL.
** Param. #1
**	The string from which create the substring.
** Param. #2
**	The start index of the substring.
** Param. #3
**	The size of the substring.
** Return value
**	The substring.
** Libc functions
**	malloc(3)
*/
