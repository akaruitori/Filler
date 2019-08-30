/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:36:02 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:58:16 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
** SYNOPSIS
**    #include <ctype.h>
**
**    int toupper(int c);
**    int tolower(int c);
**
**    int toupper_l(int c, locale_t locale);
**    int tolower_l(int c, locale_t locale);
**
** DESCRIPTION
**    These functions convert lowercase letters to uppercase, and vice
**    versa.
**
**    If c is a lowercase  letter,  toupper()  returns  its  uppercase
**    equivalent, if an uppercase representation exists in the current
**    locale.  Otherwise, it returns c.  The toupper_l() function per‐
**    forms  the  same  task,  but  uses the locale referred to by the
**    locale handle locale.
**
**    If c is a uppercase  letter,  tolower()  returns  its  lowercase
**    equivalent,  if a lowercase representation exists in the current
**    locale.  Otherwise, it returns c.  The tolower_l() function per‐
**    forms  the  same  task,  but  uses the locale referred to by the
**    locale handle locale.
**
**    If c is neither an unsigned char value nor EOF, the behavior  of
**    these functions is undefined.
** RETURN VALUE
**    The  value returned is that of the converted letter, or c if the
**    conversion was not possible.
*/
