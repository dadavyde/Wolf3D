/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:44:11 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/16 19:44:12 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		step;
	long	ln;

	ln = n;
	step = 1;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar('-');
	}
	while ((ln / step) > 9)
		step *= 10;
	while (step)
	{
		ft_putchar('0' + (ln / step));
		ln %= step;
		step /= 10;
	}
}
