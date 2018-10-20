/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:28:26 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/06 20:28:27 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*pnt;
	unsigned long	idx;
	unsigned char	*pnt_cpy;

	idx = 0;
	if (!(pnt = malloc(size)))
	{
		return (pnt);
	}
	else
	{
		pnt_cpy = (unsigned char*)pnt;
		while (idx < size)
		{
			pnt_cpy[idx] = '\0';
			idx++;
		}
		return (pnt);
	}
}
