/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:38:08 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 17:38:10 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned long	idx;
	unsigned long	idx2;

	idx = 0;
	while (s1[idx] != '\0')
		idx++;
	idx2 = 0;
	while (idx2 < n && s2[idx2] != '\0')
	{
		s1[idx] = s2[idx2];
		idx++;
		idx2++;
	}
	s1[idx] = '\0';
	return (s1);
}
