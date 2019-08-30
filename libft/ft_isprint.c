/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:19:45 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:57:40 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

/*
** SYNOPSIS
**       #include <ctype.h>
**
**       int isprint(int c);
**
** DESCRIPTION
**       These functions check whether c, which must have the value of an
**       unsigned char or EOF,  falls  into  a  certain  character  class
**       according  to  the  specified locale.  The functions without the
**       "_l" suffix perform the check based on the current locale.
**
**
**       isprint()
**              checks for any printable character including space.
**
**       RETURN VALUE
** 	         The values returned are nonzero if the character  c  falls  into
** 	         the tested class, and zero if not.
*/
