/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_all_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:49:15 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/14 15:49:16 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_del_all_c(char *s, char c)
{
	int		i;
	int		step;

	if (s == NULL)
		return ;
	i = 0;
	step = 0;
	while (s[i + step] != '\0')
	{
		while (s[i + step] != c && s[i + step] != '\0')
			i++;
		while (s[i + step] == c)
			step++;
		while (s[i + step] != c && s[i + step] != '\0')
		{
			s[i] = s[i + step];
			i++;
		}
		if (s[i + step] == '\0')
		{
			s[i] = '\0';
			break ;
		}
	}
}
