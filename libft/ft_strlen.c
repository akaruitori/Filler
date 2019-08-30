/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:31:15 by dtimeon           #+#    #+#             */
/*   Updated: 2019/05/24 11:37:53 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *str)
{
	const char	*str_temp;

	str_temp = str;
	while (*str_temp)
		str_temp++;
	return (str_temp - str);
}

/*
** SYNOPSIS
**     #include <string.h>
**
**     size_t strlen(const char *s);
**
** DESCRIPTION
**     The  strlen()  function  calculates the length of the string s,
**     excluding the terminating null byte ('\0').
**
** RETURN VALUE
**     The strlen() function returns the number of bytes in the string s.
*/
