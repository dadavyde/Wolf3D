/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:12:15 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/13 19:12:16 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		step;
	long	ln;

	ln = n;
	step = 1;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	while ((ln / step) > 9)
		step *= 10;
	while (step)
	{
		ft_putchar_fd('0' + (ln / step), fd);
		ln %= step;
		step /= 10;
	}
}
