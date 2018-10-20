/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:57:19 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/11 11:57:20 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned long	idx;

	idx = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (s1 != NULL)
		while (*s1 != '\0')
		{
			str[idx] = *s1;
			s1++;
			idx++;
		}
	if (s2 != NULL)
		while (s2 != NULL && *s2 != '\0')
		{
			str[idx] = *s2;
			s2++;
			idx++;
		}
	str[idx] = '\0';
	return (str);
}
