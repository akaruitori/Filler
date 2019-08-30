/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:23:31 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:53:32 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}

/*
** ft_striter
**
** Prototype
** 	void ft_striter(char *s, void (*f)(char *));
** Description
**	Applies the function f to each character of the string passed as argument.
**	Each character is passed by address to f to be modified if necessary.
** Param. #1
**	The string to iterate.
** Param. #2
**	The function to apply to each character of s.
** Return value
**	None
** Libc functions
**	None
*/
