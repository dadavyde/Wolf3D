/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:50:53 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/15 20:50:55 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr(const char *str, int is_negative)
{
	int				idx;
	long long int	ans;
	long long int	prev_ans;

	idx = 0;
	ans = 0;
	prev_ans = 0;
	while (ft_isdigit(str[idx]) && prev_ans <= ans)
	{
		prev_ans = ans;
		ans = ans * 10 + (str[idx++] - '0');
	}
	if (prev_ans > ans)
		return (is_negative > 0 ? (-1) : 0);
	else
		return ((int)(ans * is_negative));
}

int				ft_atoi(const char *str)
{
	int		is_negative;
	char	*str_cpy;

	is_negative = 1;
	str_cpy = (char*)str;
	while ((*str_cpy >= '\t' && *str_cpy <= '\r') || *str_cpy == ' ')
		str_cpy++;
	if (*str_cpy == '+' || *str_cpy == '-')
	{
		if (*str_cpy == '-')
			is_negative = -1;
		str_cpy++;
	}
	if (ft_isdigit(*str_cpy))
		return (ft_nbr(str_cpy, is_negative));
	else
		return (0);
}
