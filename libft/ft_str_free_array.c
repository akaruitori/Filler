/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:00:52 by dtimeon           #+#    #+#             */
/*   Updated: 2019/06/30 18:16:33 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_str_free_array(char ***array)
{
	char	**a;

	a = *array;
	while (*a)
		ft_strdel(a++);
	free(*array);
	*array = NULL;
}
