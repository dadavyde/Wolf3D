/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:20:33 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 14:20:50 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long		idx;
	unsigned char		*s1_cpy;
	unsigned char		*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	idx = 0;
	while (idx < n)
	{
		if (s1_cpy[idx] != s2_cpy[idx])
			return (s1_cpy[idx] - s2_cpy[idx]);
		idx++;
	}
	return (0);
}
