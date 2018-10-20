/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_solid_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 20:07:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/22 20:07:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_4_col_walls(t_wolf3d *sdl, int ceil_h, float ray_angle, int x)
{
	int			y;
	uint32_t	color;

	y = ceil_h;
	if (sdl->inter_position == VERTICAL)
		color = (ray_angle >= 270 || ray_angle < 90) ? 0xf4a37a : 0x60539e;
	else
		color = (ray_angle < 180) ? 0x689b83 : 0xa98cad;
	while (y < WIN_HEIGHT - ceil_h)
	{
		set_pixel(sdl->screen, x, y, color);
		y++;
	}
}

void	draw_1_col_floor_and_sky(t_wolf3d *sdl, int ceil_h, int x)
{
	int		y;

	y = 0;
	while (y < ceil_h)
	{
		set_pixel(sdl->screen, x, y, 0xaff1f7);
		y++;
	}
	y = WIN_HEIGHT - ceil_h;
	while (y < WIN_HEIGHT)
	{
		set_pixel(sdl->screen, x, y, 0x5b4c47);
		y++;
	}
}
