/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:47:31 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 17:47:33 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	idx;
	unsigned long	size_dst;

	size_dst = ft_strlen(dst);
	idx = 0;
	if (dstsize > size_dst)
	{
		while (src[idx] != '\0' && idx < (dstsize - size_dst - 1))
		{
			dst[size_dst + idx] = src[idx];
			idx++;
		}
		dst[size_dst + idx] = '\0';
		return (ft_strlen(src) + size_dst);
	}
	else
		return (ft_strlen(src) + dstsize);
}
