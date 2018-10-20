/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:38:57 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/11 16:38:57 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_str(char **str, long ln, int is_negative, int step)
{
	int		idx;

	idx = 0;
	if (is_negative == 2)
	{
		(*str)[idx] = '-';
		idx++;
	}
	while (step)
	{
		(*str)[idx] = '0' + (ln / step);
		ln %= step;
		step /= 10;
		idx++;
	}
	(*str)[idx] = '\0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		is_negative;
	int		step;
	int		idx;
	long	ln;

	step = 1;
	is_negative = 1;
	idx = 0;
	ln = (long)n;
	if (ln < 0)
	{
		is_negative = 2;
		ln *= -1;
	}
	while ((ln / step) > 9)
	{
		step *= 10;
		idx++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (idx + is_negative + 1))))
		return (NULL);
	put_str(&str, ln, is_negative, step);
	return (str);
}
