/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:52:46 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 14:52:50 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*dst;

	idx = 0;
	while (s1[idx] != '\0')
		idx++;
	if (!(dst = (char*)malloc(sizeof(char) * (idx + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0')
	{
		dst[idx] = s1[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (dst);
}
