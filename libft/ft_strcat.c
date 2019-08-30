/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 07:35:54 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/20 14:23:07 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*temp_dest;

	temp_dest = dest;
	while (*temp_dest)
		temp_dest++;
	ft_strcpy(temp_dest, src);
	return (dest);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        char *strcat(char *dest, const char *src);
**
**        char *strncat(char *dest, const char *src, size_t n);
**
** DESCRIPTION
**        The strcat() function appends the src string to the dest
**        string, overwriting the terminating null byte ('\0')  at
**        the  end of dest, and then adds a terminating null byte.
**        The strings may not overlap, and the  dest  string  must
**        have  enough space for the result.  If dest is not large
**        enough, program behavior is unpredictable; buffer  over‐
**        runs  are  a  favorite  avenue for attacking secure pro‐
**        grams.
**
**        The strncat() function is similar, except that
**
**        *  it will use at most n bytes from src; and
**
**        *  src does not need to be null-terminated  if  it  con‐
**           tains n or more bytes.
**
**        As with strcat(), the resulting string in dest is always
**        null-terminated.
**
**        If src contains n or more bytes,  strncat()  writes  n+1
**        bytes  to  dest  (n  from  src plus the terminating null
**        byte).  Therefore, the size of dest  must  be  at  least
**        strlen(dest)+n+1.
**
**        A simple implementation of strncat() might be:
**
**            char *
**            strncat(char *dest, const char *src, size_t n)
**            {
**                size_t dest_len = strlen(dest);
**                size_t i;
**
**                for (i = 0 ; i < n && src[i] != '\0' ; i++)
**                    dest[dest_len + i] = src[i];
**                dest[dest_len + i] = '\0';
**
**                return dest;
**            }
**
** RETURN VALUE
**        The strcat() and strncat() functions return a pointer to
**        the resulting string dest.
*/
