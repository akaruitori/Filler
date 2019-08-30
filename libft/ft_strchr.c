/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:05:29 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/28 16:10:22 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s && *s != chr)
		s++;
	if (*s == chr)
		return ((char *)s);
	return (NULL);
}

/*
** NAME
**        strchr, strrchr, strchrnul - locate character in string
**
** SYNOPSIS
**        #include <string.h>
**
**        char *strchr(const char *s, int c);
**
**        char *strrchr(const char *s, int c);
**
**        #include <string.h>
**
** DESCRIPTION
**        The  strchr() function returns a pointer to the first occurrence of
**        the character c in the string s.
**
**        The strrchr() function returns a pointer to the last occurrence of
**        the character c in the string s.
**
**        The strchrnul() function is like strchr() except that if c is not
**        found in s, then it returns a pointer to the null  byte  at  the
**        end  of s, rather than NULL.
**
**        Here "character" means "byte"; these functions do not work with wide
**        or multibyte characters.
**
** RETURN VALUE
**        The strchr() and strrchr() functions return a pointer  to  the
**        matched character  or NULL if the character is not found.  The
**        terminating null byte is considered part of the string, so that
**        if c is  specified as'\0', these functions return a pointer to
**        the terminator.
*/
