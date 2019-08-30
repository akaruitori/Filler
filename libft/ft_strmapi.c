/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:25:42 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:25:27 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
** ft_strmapi
**
** Prototype
** 	char * ft_strmapi(char const *s, char (*f)(unsigned int, char));
** Description
**	Applies the function f to each character of the string passed as argument
**	by giving its index as first argument to create a “fresh” new string
**	(with malloc(3)) resulting from the successive applications of f.
** Param. #1
**	The string to map.
** Param. #2
**	The function to apply to each character of s and its index.
** Return value
**	The “fresh” string created from the successive applications of f.
** Libc functions
**	malloc(3)
*/
