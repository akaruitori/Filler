/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:16:57 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:48:57 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
** SYNOPSIS
**    #include <ctype.h>
**
**    int isalpha(int c);
**
** DESCRIPTION
**    These functions check whether c, which must have the value of an
**    unsigned char or EOF,  falls  into  a  certain  character  class
**    according  to  the  specified locale.  The functions without the
**    "_l" suffix perform the check based on the current locale.
**
**    isalpha()
**           checks  for  an alphabetic character; in the standard "C"
**           locale, it is equivalent to (isupper(c)  ||  islower(c)).
**           In  some  locales, there may be additional characters for
**           which isalpha() is true—letters which are neither  upper‐
**           case nor lowercase.
**
**
**   RETURN VALUE
**     The values returned are nonzero if the character  c  falls  into
**     the tested class, and zero if not.
*/
