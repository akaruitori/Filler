/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:02:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/25 18:52:46 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	return (ft_strtol(nptr, (char **)NULL, 10));
}

/*
** SYNOPSIS
**       #include <stdlib.h>
**
**       int atoi(const char *nptr);
**
** DESCRIPTION
**	The atoi() function converts the initial portion of the  string  pointed
**	to by nptr to int.  The behavior is the same as
**
**		strtol(nptr, NULL, 10);
**
** 	except that atoi() does not detect errors.
**
**	The  atol()  and  atoll()  functions behave the same as atoi(), except that
**	they convert the initial portion of the string to their return type of long
**	or  long long.
**
** RETURN VALUE
**	The converted value.
*/
