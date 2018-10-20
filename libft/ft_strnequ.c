/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:31:56 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 21:31:57 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned long	idx;

	if (s1 == NULL || s2 == NULL)
		return (0);
	idx = 0;
	while (idx < n && s1[idx] != '\0' && s1[idx] == s2[idx])
		idx++;
	if (idx == n)
		return (s1[idx - 1] == s2[idx - 1]);
	else
		return (s1[idx] == s2[idx]);
}
