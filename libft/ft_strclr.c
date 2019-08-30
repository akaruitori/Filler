/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:15:31 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:52:52 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

/*
** ft_strclr
**
** Prototype
** 	void ft_strclr(char *s);
** Description
**	Sets every character of the string to the value ’\0’.
** Param. #1
**	The string that needs to be cleared.
** Return value
**	None
** Libc functions
**	None.
*/
