/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_after_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:48:11 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/14 19:48:12 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_after_c(const char *s, int c)
{
	int		idx;
	char	c_cpy;
	char	*s_cpy;
	int		count;

	c_cpy = (char)c;
	s_cpy = (char*)s;
	idx = 0;
	count = 0;
	while (s_cpy[idx] != c_cpy && s_cpy[idx] != '\0')
		idx++;
	while (s_cpy[idx] == c_cpy)
		idx++;
	return ((s_cpy[idx] != '\0') ? &(s_cpy[idx]) : NULL);
}
