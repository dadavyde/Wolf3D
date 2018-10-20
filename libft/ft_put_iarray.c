/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_iarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:41:57 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/14 15:41:58 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_iarray(int *arr, size_t size_arr, char *delimiter)
{
	unsigned long		i;

	i = 0;
	while (i < size_arr)
	{
		ft_putnbr(arr[i]);
		ft_putstr(delimiter);
		i++;
	}
}
