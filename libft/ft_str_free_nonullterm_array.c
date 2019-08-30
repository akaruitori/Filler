/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free_nonullterm_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 01:35:56 by dtimeon           #+#    #+#             */
/*   Updated: 2019/06/30 17:58:31 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_str_free_nonullterm_array(char ***array, size_t size)
{
	char	**a;

	a = *array;
	while (size--)
		ft_strdel(a++);
	free(*array);
	*array = NULL;
}
