/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:25:37 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:25:15 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
		result[i] = f(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
** ft_strmap
**
** Prototype
** 	char * ft_strmap(char const *s, char (*f)(char));
** Description
**	Applies the function f to each character of the string given as argument
**	to create a “fresh” new string (with malloc(3)) resulting from
**	the successive applications of f.
** Param. #1
**	The string to map.
** Param. #2
**	The function to apply to each character of s.
** Return value
**	The “fresh” string created from the successive applications of f.
** Libc functions
**	malloc(3)
*/
