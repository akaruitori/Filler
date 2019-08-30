/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:27:57 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/23 20:46:37 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 && *s1 == *s2) && n--)
	{
		s1++;
		s2++;
	}
	if (n)
		return ((int)((unsigned char)*s1 - (unsigned char)*s2));
	return (0);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        int strcmp(const char *s1, const char *s2);
**
**        int strncmp(const char *s1, const char *s2, size_t n);
**
** DESCRIPTION
**        The  strcmp()  function  compares the two strings s1 and s2.  It
**        returns an integer less than, equal to, or greater than zero  if
**        s1  is  found,  respectively,  to  be less than, to match, or be
**        greater than s2.
**
**        The strncmp() function is similar, except it compares  only  the
**        first (at most) n bytes of s1 and s2.
**
** RETURN VALUE
**        The  strcmp()  and  strncmp()  functions  return an integer less
**        than, equal to, or greater than zero if s1 (or the first n bytes
**        thereof)  is  found, respectively, to be less than, to match, or
**        be greater than s2.
*/
