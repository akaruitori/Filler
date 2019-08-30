/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 09:18:46 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/29 16:10:35 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (size + src_len);
	size -= dst_len + 1;
	ft_strncat(dst, src, size);
	return (dst_len + src_len);
}

/*
** NAME
**
**      strlcpy, strlcat -- size-bounded string copying and concatenation
**
** LIBRARY
**
**      Standard C Library (libc, -lc)
**
** SYNOPSIS
**
**      #include <string.h>
**
**      size_t
**      strlcpy(char *dst, const char *src, size_t size);
**
**      size_t
**      strlcat(char *dst, const char *src, size_t size);
**
** DESCRIPTION
**
**      The strlcpy() and strlcat() functions copy and concatenate strings
** 	 respectively.  They are designed to be safer, more consistent, and less
**      error prone replacements for strncpy(3) and strncat(3).  Unlike those
** 	 functions, strlcpy() and strlcat() take the full size of the buffer
**      (not just the length) and guarantee to NUL-terminate the result (as
** 	 long as size is larger than 0 or, in the case of strlcat(), as long as
**      there is at least one byte free in dst).  Note that you should include
** 	 a byte for the NUL in size.  Also note that strlcpy() and strlcat()
**      only operate on true C strings.  This means that for strlcpy()
** 	 src must be NUL-terminated and for strlcat() both src and dst must be NUL-
**      terminated.
**
**      The strlcpy() function copies up to size - 1 characters from the NUL-
** 	 terminated string src to dst, NUL-terminating the result.
**
**      The strlcat() function appends the NUL-terminated string src to the
** 	 end of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-
**      terminating the result.
**
** RETURN VALUES
**
**      The strlcpy() and strlcat() functions return the total length of the
** 	 string they tried to create.	For strlcpy() that means the length of
**      src.  For strlcat() that means the initial length of dst plus the
** 	 length of src.  While this may seem somewhat confusing it was done to make
**      truncation detection simple.
**
**      Note however, that if strlcat() traverses size characters without
** 	 finding a NUL, the length of the string is considered to be size and the
**      destination string will not be NUL-terminated (since there was no space
** 	 for the NUL).  This keeps strlcat() from running off the end of a
**      string.  In practice this should not happen (as it means that either
** 	 size is incorrect or that dst is not a proper ``C'' string).	The check
**      exists to prevent potential security problems in incorrect code.
**
** EXAMPLES
**
**      The following code fragment illustrates the simple case:
**
** 	   char *s, *p, buf[BUFSIZ];
**
** 	   ...
**
** 	   (void)strlcpy(buf, s, sizeof(buf));
** 	   (void)strlcat(buf, p, sizeof(buf));
**
**      To detect truncation, perhaps while building a pathname, something like
** 	 the following might be used:
**
** 	   char *dir, *file, pname[MAXPATHLEN];
**
** 	   ...
**
** 	   if (strlcpy(pname, dir, sizeof(pname)) >= sizeof(pname))
** 		   goto toolong;
** 	   if (strlcat(pname, file, sizeof(pname)) >= sizeof(pname))
** 		   goto toolong;
**
**      Since we know how many characters we copied the first time, we can
** 	 speed things up a bit by using a copy instead of an append:
**
** 	   char *dir, *file, pname[MAXPATHLEN];
** 	   size_t n;
**
** 	   ...
**
** 	   n = strlcpy(pname, dir, sizeof(pname));
** 	   if (n >= sizeof(pname))
** 		   goto toolong;
** 	   if (strlcpy(pname + n, file, sizeof(pname) - n) >= sizeof(pname) - n)
** 		   goto toolong;
**
**      However, one may question the validity of such optimizations, as they
** 	 defeat the whole purpose of strlcpy() and strlcat().
*/
