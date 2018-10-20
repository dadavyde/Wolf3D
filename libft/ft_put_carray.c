/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_carray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:34:40 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/14 15:34:42 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_carray(char **arr, size_t size_arr, char *delimiter)
{
	unsigned long		i;

	i = 0;
	while (i < size_arr)
	{
		ft_putstr(arr[i]);
		ft_putstr(delimiter);
		i++;
	}
}
