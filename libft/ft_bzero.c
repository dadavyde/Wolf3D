/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:52:54 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/03 20:55:20 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long		idx;
	unsigned char		*a;

	idx = 0;
	a = (unsigned char*)s;
	while (idx < n)
	{
		a[idx] = '\0';
		idx++;
	}
}
