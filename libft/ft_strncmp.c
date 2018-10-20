/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:31:10 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 21:31:11 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	idx;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	idx = 0;
	while (idx < n && s1_cpy[idx] != '\0' && s1_cpy[idx] == s2_cpy[idx])
		idx++;
	if (idx == n)
		return (0);
	else
		return (s1_cpy[idx] - s2_cpy[idx]);
}
