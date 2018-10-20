/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cpy_to_int_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:07:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/07 14:07:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_str_cpy_to_int_arr(char *str, int len)
{
	int		idx_x;
	int		*arr;

	idx_x = 0;
	arr = malloc(sizeof(int) * len);
	while (str[idx_x])
	{
		if (ft_isdigit(str[idx_x]))
			arr[idx_x] = str[idx_x] - '0';
		else
			return (NULL);
		idx_x++;
	}
	return (arr);
}
