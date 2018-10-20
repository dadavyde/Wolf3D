/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:13:17 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/10 21:13:18 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned long	idx;
	unsigned int	idx2;

	if (s == NULL)
		return (NULL);
	idx = 0;
	idx2 = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[idx2] != '\0')
	{
		str[idx] = f(idx2, s[idx2]);
		idx++;
		idx2++;
	}
	str[idx] = '\0';
	return (str);
}
