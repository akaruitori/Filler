/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:03:50 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/23 20:06:40 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}

/*
** ft_putnbr
**
** Prototype
** 	void ft_putnbr(int n);
** Description
**	Outputs the integer n to the standard output.
** Param. #1
**	The integer to output.
** Return value
**	None
** Libc functions
**	write(2).
*/
