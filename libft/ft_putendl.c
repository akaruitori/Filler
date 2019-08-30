/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:03:24 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/22 01:03:42 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}

/*
** ft_putendl
**
** Prototype
** 	void ft_putendl(char const *s);
** Description
**	Outputs the string s to the standard output followed by a ’\n’.
** Param. #1
**	The string to output.
** Return value
**	None
** Libc functions
**	write(2)
*/
