/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recount_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:22:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/26 21:22:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	recount_float_angle(float *f_angle)
{
	if (!f_angle)
		return ;
	if (*f_angle < 0)
		*f_angle += 360;
	if (*f_angle >= 360)
		*f_angle -= 360;
}

void	recount_int_angle(int *i_angle)
{
	if (!i_angle)
		return ;
	if (*i_angle < 0)
		*i_angle += 360;
	if (*i_angle >= 360)
		*i_angle -= 360;
}
