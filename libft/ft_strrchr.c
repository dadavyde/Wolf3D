/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:16:22 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 19:16:23 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
		idx++;
	while (idx >= 0)
	{
		if (s_cpy[idx] == c_cpy)
		{
			pnt = &s_cpy[idx];
			break ;
		}
		idx--;
	}
	return (pnt);
}
