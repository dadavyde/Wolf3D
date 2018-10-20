/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:23:59 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 21:24:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		idx;

	if (s1 == NULL || s2 == NULL)
		return (0);
	idx = 0;
	while (s1[idx] != '\0' && s1[idx] == s2[idx])
		idx++;
	return (s1[idx] == s2[idx]);
}
