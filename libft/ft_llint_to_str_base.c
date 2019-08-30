/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llint_to_str_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:08:25 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/15 18:31:43 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int					count_len(long long int n, int base)
{
	int						len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char						*ft_llint_to_str_base(long long int n, int base)
{
	int						sign;
	char					*digits;
	int						len;
	char					*result;
	unsigned long long int	unum;

	if (n == 0)
		return (ft_strdup("0"));
	sign = ((n < 0 && base == 10) ? -1 : 1);
	digits = "0123456789abcdef";
	len = count_len(n, base);
	if (sign == -1)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	unum = ((n >= 0) ? n : -n);
	while (len--)
	{
		result[len] = digits[unum % base];
		unum /= base;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
