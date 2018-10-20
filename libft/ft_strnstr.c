/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:58:45 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 20:58:46 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	idx;
	unsigned long	idx2;

	idx = 0;
	if (needle[idx] == '\0')
		return ((char*)haystack);
	while (haystack[idx] != '\0')
	{
		idx2 = 0;
		while (idx < len && haystack[idx] != *needle && haystack[idx] != '\0')
			idx++;
		if (haystack[idx] == '\0')
			break ;
		while ((idx + idx2) < len && needle[idx2] != '\0' &&
				needle[idx2] == haystack[idx + idx2])
			idx2++;
		if (needle[idx2] == '\0')
			return ((char*)&(haystack[idx]));
		idx++;
	}
	return (NULL);
}
