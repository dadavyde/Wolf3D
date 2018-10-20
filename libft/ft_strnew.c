/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:55:31 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 19:55:33 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned long	idx;

	idx = 0;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (idx < size)
	{
		str[idx] = 0;
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
