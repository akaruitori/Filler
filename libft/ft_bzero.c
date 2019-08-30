/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:47:13 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 16:20:03 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
** SYNOPSIS
**        #include <strings.h>
**
**        void bzero(void *s, size_t n);
**
** DESCRIPTION
**        The bzero() function sets the first n bytes of the area
** 	   starting at s to zero (bytes containing '\0').
**
** RETURN VALUE
**        None.
*/
