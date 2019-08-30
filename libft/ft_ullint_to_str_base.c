/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullint_to_str_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:34:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/28 16:11:18 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <inttypes.h>

static int	count_len(unsigned long long int n, int base)
{
	int		len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char		*ft_ullint_to_str_base(unsigned long long int n, int base)
{
	char	*digits;
	int		len;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	digits = "0123456789abcdef";
	len = count_len(n, base);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = digits[n % base];
		n /= base;
	}
	return (result);
}
