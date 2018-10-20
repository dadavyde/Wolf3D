/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:45:30 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 15:45:33 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	idx;

	idx = 0;
	while (idx < len && src[idx] != '\0')
	{
		dst[idx] = src[idx];
		idx++;
	}
	while (idx < len)
	{
		dst[idx] = '\0';
		idx++;
	}
	return (dst);
}
