/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:23:25 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 14:24:28 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2) == 0);
	return (0);
}

/*
** ft_strequ
**
** Prototype
** 	int ft_strequ(char const *s1, char const *s2);
** Description
**	Lexicographical comparison between s1 and s2. If the 2 strings are
**	identical the function returns 1, or 0 otherwise.
** Param. #1
**	The first string to be compared.
** Param. #2
**	The second string to be compared.
** Return value
**	1 or 0 according to if the 2 strings are identical or not.
** Libc functions
**	None
*/
