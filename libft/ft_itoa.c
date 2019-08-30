/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:20:37 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/27 15:26:20 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	length_of(int n)
{
	int		len;

	len = (n >= 0) ? 1 : 2;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*s;

	sign = (n >= 0) ? 1 : -1;
	len = length_of(n);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	while (--len)
	{
		s[len] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	s[len] = (sign > 0) ? (n + 48) : '-';
	return (s);
}

/*
** ft_itoa
**
** Prototype
** 	char * ft_itoa(int n);
** Description
** 	Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
**	representing the integer n given as argument. Negative numbers must be
**	supported. If the allocation fails, the function returns NULL.
** Param. #1
**	The integer to be transformed into a string.
** Return value
** 	The string representing the integer passed as argument.
** Libc functions
** 	malloc(3)
*/
