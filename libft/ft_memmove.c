/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:37:41 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/03 21:37:43 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	idx;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char*)dst;
	src_cpy = (unsigned char*)src;
	idx = 0;
	if (dst_cpy <= src_cpy)
		while (idx < len)
		{
			dst_cpy[idx] = src_cpy[idx];
			idx++;
		}
	else
	{
		idx = len - 1;
		while (idx + 1 >= 1)
		{
			dst_cpy[idx] = src_cpy[idx];
			idx--;
		}
	}
	return (dst);
}
