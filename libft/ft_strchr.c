/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:29:33 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 18:29:35 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	*pnt;
	char	c_cpy;
	char	*s_cpy;

	c_cpy = (char)c;
	s_cpy = (char*)s;
	idx = 0;
	pnt = NULL;
	while (s_cpy[idx] != '\0')
	{
		if (s_cpy[idx] == c_cpy)
		{
			pnt = &s_cpy[idx];
			break ;
		}
		idx++;
	}
	if (c_cpy == '\0')
		pnt = &s_cpy[idx];
	return (pnt);
}
