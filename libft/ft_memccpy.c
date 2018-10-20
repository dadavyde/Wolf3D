/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:13:43 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 17:13:44 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long		idx;
	unsigned char		*dst_cpy;
	unsigned char		*src_cpy;
	unsigned char		c_cpy;

	dst_cpy = (unsigned char*)dst;
	src_cpy = (unsigned char*)src;
	c_cpy = (unsigned char)c;
	idx = 0;
	while (idx < n && src_cpy[idx] != c_cpy)
	{
		dst_cpy[idx] = src_cpy[idx];
		idx++;
	}
	if (idx == n)
		return (NULL);
	else
	{
		dst_cpy[idx] = src_cpy[idx];
		idx++;
		return (&(dst[idx]));
	}
}
