/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:08:35 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/03 21:08:38 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long		idx;
	unsigned char		*dst_cpy;
	unsigned char		*src_cpy;

	dst_cpy = (unsigned char*)dst;
	src_cpy = (unsigned char*)src;
	idx = 0;
	while (idx < n)
	{
		dst_cpy[idx] = src_cpy[idx];
		idx++;
	}
	return (dst);
}
