/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:23:37 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:53:45 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}

/*
** ft_striteri
**
** Prototype
** 	void ft_striteri(char *s, void (*f)(unsigned int, char *));
** Description
**	Applies the function f to each character of the string passed as argument,
**	and passing its index as first argument. Each character is passed by
**	address to f to be modified if necessary.
** Param. #1
**	The string to iterate.
** Param. #2
**	The function to apply to each character of s and its index.
** Return value
**	None
** Libc functions
**	None
*/
