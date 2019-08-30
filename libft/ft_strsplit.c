/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:30:51 by dtimeon           #+#    #+#             */
/*   Updated: 2019/04/28 17:02:36 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	*add_word(const char *s, char c)
{
	char	*word;
	int		i;
	size_t	word_len;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word_len = i;
	if (!(word = (char *)malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	while (i)
	{
		*word++ = *s++;
		i--;
	}
	*word = '\0';
	word -= word_len;
	return (word);
}

static void	free_strings_array(char ***array, int len)
{
	char	**a;

	a = *array;
	while (len--)
		free(*a++);
	free(*array);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	number_of_words;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	number_of_words = count_words(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (number_of_words + 1))))
		return (NULL);
	while (number_of_words > i)
	{
		while (*s == c)
			s++;
		if (!(array[i] = add_word(s, c)))
		{
			free_strings_array(&array, i);
			return (NULL);
		}
		s += ft_strlen(array[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}

/*
** ft_strsplit
**
** Prototype
** 	char ** ft_strsplit(char const *s, char c);
** Description
**	Allocates (with malloc(3)) and returns an array of “fresh” strings (all
**	ending with ’\0’, including the array itself) obtained by spliting s using
**	the character c as a delimiter. If the allocation fails the function
**	returns NULL. Example: ft_strsplit("*hello*fellow***students*", ’*’)
**	returns the array ["hello", "fellow", "students"].
** Param. #1
**	The string to split.
** Param. #2
**	The delimiter character.
** Return value
**	The array of “fresh” strings result of the split.
** Libc functions
**	malloc(3), free(3)
*/
