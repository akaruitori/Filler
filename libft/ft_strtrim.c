/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:34:25 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/23 18:29:50 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_any_word_ahead(const char *s)
{
	while (*s)
	{
		if (!ft_isspace(*s))
			return (1);
		s++;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	char	*result;
	size_t	start;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	start = i;
	while (!ft_isspace(s[i]) || is_any_word_ahead(s + i))
		i++;
	len = i - start;
	if (!(result = ft_strsub(s, start, len)))
		return (NULL);
	return (result);
}

/*
** ft_strtrim
**
** Prototype
** 	;
** Description
**	Allocates (with malloc(3)) and returns a copy of the string given as
**	argument without whitespaces at the beginning or at the end of the string.
**	Will be considered as whitespaces the following characters ’ ’, ’\n’ and
**	’\t’. If s has no whitespaces at the beginning or at the end, the function
**	returns a copy of s. If the allocation fails the function returns NULL.
** Param. #1
**	The string to be trimed.
** Return value
**	The “fresh” trimmed string or a copy of s.
** Libc functions
**	malloc(3)
*/
