/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:49:32 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/11 14:49:33 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_of_words(char const *str, char c)
{
	int		inx;
	int		count_of_words;

	inx = 0;
	count_of_words = 0;
	while (str[inx] != '\0')
	{
		while ((str[inx]) != c && str[inx] != '\0')
			inx++;
		count_of_words++;
		while ((str[inx]) == c && str[inx] != '\0')
			inx++;
	}
	return (count_of_words);
}

static int		size_of_word(char const *str, char c)
{
	int		size_of_word;

	size_of_word = 0;
	while (str[size_of_word] != c && str[size_of_word] != '\0')
		size_of_word++;
	return (size_of_word);
}

static int		del(char ***array, int i)
{
	int		idx;

	idx = 0;
	if ((*array)[i] == NULL)
	{
		while (idx < i)
		{
			free((*array)[idx]);
			idx++;
		}
		free(*array);
		return (1);
	}
	else
		return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**array;
	int		size;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	if (!(array = malloc(sizeof(char*) * (num_of_words(s, c) + 1))))
		return (NULL);
	while (*s != '\0')
	{
		size = size_of_word(s, c);
		if (!(array[i] = malloc(sizeof(char) * (size + 1))) && del(&array, i))
			return (NULL);
		array[i] = ft_strncpy(array[i], s, size);
		array[i][size] = '\0';
		s += size;
		while (*s == c)
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
