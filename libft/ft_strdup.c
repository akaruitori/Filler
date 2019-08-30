/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:30:55 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:23:36 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        char *strdup(const char *s);
**
**        char *strndup(const char *s, size_t n);
**        char *strdupa(const char *s);
**        char *strndupa(const char *s, size_t n);
**
** DESCRIPTION
**        The strdup() function returns a pointer to a  new  string  which  is
**< a
**        duplicate  of the string s.  Memory for the new string is obtained
**< with
**        malloc(3), and can be freed with free(3).
**
**        The strndup() function is similar, but copies at most n bytes.  If s
**< is
**        longer  than  n,  only  n bytes are copied, and a terminating null
**< byte
**        ('\0') is added.
**
**        strdupa() and strndupa() are similar, but use alloca(3) to allocate
**< the
**        buffer.  They are available only when using the GNU GCC suite, and
**< suf‐
**        fer from the same limitations described in alloca(3).
**
** RETURN VALUE
**        On success, the strdup() function returns a pointer to  the
**< duplicated
**        string.   It  returns  NULL  if insufficient memory was available,
**< with
**        errno set to indicate the cause of the error.
**
** ERRORS
**        ENOMEM Insufficient memory available to allocate duplicate string.
*/
