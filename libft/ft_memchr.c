/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:53:27 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 13:53:28 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long		idx;
	unsigned char		*s_cpy;
	unsigned char		c_cpy;
	unsigned char		*pnt;

	s_cpy = (unsigned char*)s;
	c_cpy = (unsigned char)c;
	idx = 0;
	pnt = NULL;
	while (idx < n)
	{
		if (s_cpy[idx] == c_cpy)
		{
			pnt = &s_cpy[idx];
			break ;
		}
		idx++;
	}
	return (pnt);
}
