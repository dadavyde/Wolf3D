/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:30:46 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/11 12:30:47 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		whitespaces(char const *s, int idx)
{
	if (idx < 1)
	{
		while (s[idx] == ' ' || s[idx] == '\n' || s[idx] == '\t')
			idx++;
		if (s[idx] == '\0')
			return (-1);
	}
	else
		while (s[idx] == ' ' || s[idx] == '\n' || s[idx] == '\t')
			idx--;
	return (idx);
}

char			*ft_strtrim(char const *s)
{
	unsigned long	size;
	unsigned long	idx;
	char			*str;

	if (s == NULL)
		return (NULL);
	s += whitespaces(s, 0);
	size = whitespaces(s, (ft_strlen(s) - 1)) + 1;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		str[idx] = s[idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
