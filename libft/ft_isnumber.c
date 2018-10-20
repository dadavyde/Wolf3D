/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 20:36:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/06 20:36:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str_num, int sign)
{
	if (sign && (*str_num == '+' || *str_num == '-'))
		str_num++;
	while (*str_num)
	{
		if (!ft_isdigit((int)*str_num))
			return (0);
		str_num++;
	}
	return (1);
}
