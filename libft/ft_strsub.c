/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:37:09 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 21:37:11 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned long	idx;

	if (s == NULL || len <= 0)
		return (NULL);
	idx = 0;
	if (!(sub_s = malloc(len + 1)))
		return (NULL);
	s += start;
	while (idx < len)
	{
		sub_s[idx] = s[idx];
		idx++;
	}
	sub_s[idx] = '\0';
	return (sub_s);
}
