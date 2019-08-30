/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:27:31 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/25 20:26:49 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

/*
** ft_lstnew
** 	Prototype
** t_list * ft_lstnew(void const *content, size_t content_size);
** 	Description
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are ini-
** tialized by copy of the parameters of the function. If the pa-
** rameter content is nul, the variable content is initialized to
** NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is
** initialized to NULL. If the allocation fails, the function returns
** NULL.
** 	Param. #1
** The content to put in the new link.
** 	Param. #2
** The size of the content of the new link.
** 	Return value
** The new link.
** 	Libc functions
** malloc(3), free(3)
*/
