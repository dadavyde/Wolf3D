/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:15:39 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/14 20:15:40 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraycpy(char const **src, int size)
{
	int		i;
	char	**dst;
	int		flag;

	flag = 0;
	if (size == 0)
	{
		while (src[size] != NULL)
			size++;
		flag = 1;
	}
	dst = (char**)malloc(sizeof(char*) * (size + flag));
	i = 0;
	while (i < size)
	{
		dst[i] = ft_strnew(ft_strlen(src[i]));
		ft_strcpy(dst[i], src[i]);
		i++;
	}
	if (flag)
		dst[i] = NULL;
	return (dst);
}
