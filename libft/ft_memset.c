/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:35:42 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 17:35:44 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	idx;
	unsigned char	*a;
	unsigned char	d;

	idx = 0;
	a = (unsigned char*)b;
	d = (unsigned char)c;
	while (idx < len)
	{
		a[idx] = d;
		idx++;
	}
	return (a);
}
