/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:32:54 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/28 16:10:48 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!(needle_len = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack && len--)
	{
		i = 0;
		while ((*(haystack + i) == needle[i]) && (len - i + 1))
		{
			if (i == (needle_len - 1))
				return ((char *)(haystack));
			i++;
		}
		haystack++;
	}
	return (0);
}

/*
** SYNOPSIS
**      #include <string.h>
**
**      char *
**      strstr(const char *haystack, const char *needle);
**
**      char *
**      strcasestr(const char *haystack, const char *needle);
**
**      char *
**      strnstr(const char *haystack, const char *needle, size_t len);
**
**      #include <string.h>
**      #include <xlocale.h>
**
**      char *
**      strcasestr_l(const char *haystack, const char *needle, locale_t loc);
**
** DESCRIPTION
**      The strstr() function locates the first occurrence of the null-termi-
**      nated string needle in the null-terminated string haystack.
**
**      The strcasestr() function is similar to strstr(), but ignores the case
**      of both strings.
**
**      The strnstr() function locates the first occurrence of the null-termi-
**      nated string needle in the string haystack, where not more than len
**      characters are searched.  Characters that appear after a `\0' character
**      are not searched.  Since the strnstr() function is a FreeBSD specific
**      API, it should only be used when portability is not a concern.
**
**      While the strcasestr() function uses the current locale, the
**      strcasestr_l() function may be passed a locale directly. See xlocale(3)
**      for more information.
**
** RETURN VALUES
**      If needle is an empty string, haystack is returned; if needle occurs
**      nowhere in haystack, NULL is returned; otherwise a pointer to the first
**      character of the first occurrence of needle is returned.
**
** EXAMPLES
**      The following sets the pointer ptr to the "Bar Baz" portion of
**      largestring:
**
**            const char *largestring = "Foo Bar Baz";
**            const char *smallstring = "Bar";
**            char *ptr;
**
**            ptr = strstr(largestring, smallstring);
**
**      The following sets the pointer ptr to NULL, because only the first 4
**      characters of largestring are searched:
**
**            const char *largestring = "Foo Bar Baz";
**            const char *smallstring = "Bar";
**            char *ptr;
**
**            ptr = strnstr(largestring, smallstring, 4);
*/
