/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:23:43 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/23 17:30:18 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
		*(result++) = *(s1++);
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (result - len);
}

/*
** ft_strjoin
**
** Prototype
** 	char * ft_strjoin(char const *s1, char const *s2);
** Description
**	Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
**	result of the concatenation of s1 and s2. If the allocation fails
**	the function returns NULL.
** Param. #1
**	The prefix string.
** Param. #2
**	The suffix string.
** Return value
**	The “fresh” string result of the concatenation of the 2 strings.
** Libc functions
**	malloc(3)
*/
