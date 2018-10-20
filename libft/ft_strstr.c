/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:26:31 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 19:26:33 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		idx;
	int		idx2;

	idx = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[idx] != '\0')
	{
		idx2 = 0;
		while (haystack[idx] != *needle && haystack[idx] != '\0')
			idx++;
		if (haystack[idx] == '\0')
			break ;
		while (needle[idx2] != '\0' && needle[idx2] == haystack[idx + idx2])
			idx2++;
		if (needle[idx2] == '\0' && \
		needle[idx2 - 1] == haystack[idx + idx2 - 1])
			return ((char*)&(haystack[idx]));
		idx++;
	}
	return (NULL);
}
