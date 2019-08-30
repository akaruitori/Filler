/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:16:42 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:20:36 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

/*
** SYNOPSIS
**        #include <ctype.h>
**
**        int isalnum(int c);
**
** DESCRIPTION
**        These functions check whether c, which must have the value of an
**        unsigned char or EOF,  falls  into  a  certain  character  class
**        according  to  the  specified locale.  The functions without the
**        "_l" suffix perform the check based on the current locale.
**
**        isalnum()
**               checks for an alphanumeric character; it is equivalent to
**               (isalpha(c) || isdigit(c)).
**
** 	  RETURN VALUE
** 	         The values returned are nonzero if the character  c  falls  into
** 	         the tested class, and zero if not.
*/
