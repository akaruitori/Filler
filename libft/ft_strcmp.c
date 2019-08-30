/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:27:26 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:23:12 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
** SYNOPSIS
**        #include <string.h>
**
**        int strcmp(const char *s1, const char *s2);
**
**        int strncmp(const char *s1, const char *s2, size_t n);
**
** DESCRIPTION
**        The  strcmp()  function  compares  the two strings s1 and s2.  It
** 	   returns an integer less
**        than, equal to, or greater than zero if s1 is found, respectively,
** 	   to be  less  than,  to
**        match, or be greater than s2.
**
**        The strncmp() function is similar, except it compares only the first
** 	   (at most) n bytes of
**        s1 and s2.
**
** RETURN VALUE
**        The strcmp() and strncmp() functions return an integer less than,
** 	   equal  to,  or  greater
**        than  zero  if s1 (or the first n bytes thereof) is found,
** 	   respectively, to be less than,
**        to match, or be greater than s2.
*/
