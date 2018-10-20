/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:27:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/22 18:27:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_sky(t_wolf3d *wolf, int ceil_h, int x, float ray_angle)
{
	int			y;
	float		dy;
	t_fpoint	texture_dot;
	uint32_t	color;

	y = 0;
	texture_dot.x = (int)(ray_angle * wolf->textures[SKY]->w / 360);
	dy = (float)wolf->textures[SKY]->w /
			(float)(360 / ANGLE_OF_VIEW * WIN_WIDTH);
	texture_dot.y = wolf->textures[SKY]->h - dy * (WIN_HEIGHT / 2);
	while (y < ceil_h)
	{
		color = get_pixel(wolf->textures[SKY],
						(int)texture_dot.x, (int)texture_dot.y);
		set_pixel(wolf->screen, x, y, color);
		texture_dot.y += dy;
		y++;
	}
}

void	draw_texture_walls(t_wolf3d *wolf, int wall_h, int x,
							t_fpoint p_intersect)
{
	int			y;
	t_fpoint	texture_dot;
	float		dy;
	int			ceil_h;
	uint32_t	color;

	ceil_h = (WIN_HEIGHT - wall_h) / 2 + 1;
	if (ceil_h < 0)
		ceil_h = 0;
	dy = (float)wolf->textures[wolf->wall_number]->h / (float)(wall_h);
	y = ceil_h;
	texture_set_param(wolf, p_intersect, &texture_dot, wall_h);
	while (y < WIN_HEIGHT - ceil_h)
	{
		color = get_pixel(wolf->textures[wolf->wall_number], (int)texture_dot.x,
						(int)texture_dot.y);
		set_pixel(wolf->screen, x, y, color);
		texture_dot.y += dy;
		y++;
	}
}

void	texture_set_param(t_wolf3d *wolf, t_fpoint p_intersect,
						t_fpoint *texture, int wall_h)
{
	if (wolf->inter_position == VERTICAL)
		texture->x = ((int)(p_intersect.y / BLOCK_SIZE *
				wolf->textures[wolf->wall_number]->w) %
				wolf->textures[wolf->wall_number]->w);
	else
		texture->x = ((int)(p_intersect.x / BLOCK_SIZE *
				wolf->textures[wolf->wall_number]->w) %
				wolf->textures[wolf->wall_number]->w);
	if (wall_h > WIN_HEIGHT)
		texture->y = (wall_h - WIN_HEIGHT) / 2 *
					(float)wolf->textures[wolf->wall_number]->h /
				(float)(wall_h);
	else
		texture->y = 0;
}

void	draw_texture_floor(t_wolf3d *wolf, int wall_h, int x, float ray_angle)
{
	float		dist_to_floor;
	t_point		texture_dot;
	float		coefficient;
	int			y;
	uint32_t	color;

	y = (WIN_HEIGHT + wall_h) / 2;
	coefficient = (wolf->dist_to_project_screen * BLOCK_SIZE) /
			cosf(RADIANS(ray_angle - wolf->player.angle));
	while (y < WIN_HEIGHT)
	{
		dist_to_floor = coefficient / (float)wall_h;
		texture_dot = get_floor_texture_coord(wolf, dist_to_floor, ray_angle);
		color = get_pixel(wolf->textures[FLOOR], texture_dot.x, texture_dot.y);
		set_pixel(wolf->screen, x, y, color);
		y++;
		wall_h += 2;
	}
}

t_point	get_floor_texture_coord(t_wolf3d *wolf, float dist_to_floor,
									float ray_angle)
{
	t_fpoint	p_cross_floor;
	t_point		texture_dot;

	p_cross_floor.x = ((int)wolf->player.coord.x +
					dist_to_floor * cosf(RADIANS(ray_angle)));
	p_cross_floor.y = (float)((int)wolf->player.coord.y -
					dist_to_floor * sin(RADIANS(ray_angle)));
	texture_dot.x = ((int)(wolf->textures[FLOOR]->w / BLOCK_SIZE *
			p_cross_floor.x) % wolf->textures[FLOOR]->w);
	texture_dot.y = ((int)(wolf->textures[FLOOR]->w / BLOCK_SIZE *
			p_cross_floor.y) % wolf->textures[FLOOR]->h);
	return (texture_dot);
}
