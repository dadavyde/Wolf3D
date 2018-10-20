/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:40:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/09 13:40:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		draw_scene(t_wolf3d *sdl)
{
	int		left_bound;
	int		ray_idx;
	float	ray_angle;

	recount_int_angle(&(sdl->player.angle));
	left_bound = sdl->player.angle + ANGLE_OF_VIEW / 2;
	ray_idx = 0;
	while (ray_idx < WIN_WIDTH)
	{
		ray_angle = ((left_bound - (sdl->angle_step * ray_idx)));
		recount_float_angle(&ray_angle);
		draw_ray(sdl, ray_idx, ray_angle);
		ray_idx++;
	}
	return (0);
}

int		draw_ray(t_wolf3d *wolf, int x, float ray_angle)
{
	float		dist_to_wall;
	t_fpoint	p_intersect;
	int			ceil_h;
	int			wall_h;

	set_some_param(wolf, &p_intersect, ray_angle, &dist_to_wall);
	wall_h = (int)(wolf->dist_to_project_screen * BLOCK_SIZE / dist_to_wall);
	ceil_h = (wall_h > WIN_HEIGHT) ? 0 : (WIN_HEIGHT - wall_h) / 2 + 1;
	if (wolf->is_texture == TRUE)
	{
		draw_texture_walls(wolf, wall_h, x, p_intersect);
		draw_sky(wolf, ceil_h, x, ray_angle);
		draw_texture_floor(wolf, wall_h, x, ray_angle);
	}
	else
	{
		draw_4_col_walls(wolf, ceil_h, ray_angle, x);
		draw_1_col_floor_and_sky(wolf, ceil_h, x);
	}
	return (0);
}

void	set_some_param(t_wolf3d *wolf, t_fpoint *p_intersect, float ray_angle,
						float *dist_to_wall)
{
	*p_intersect = find_closest_intersection(wolf, ray_angle);
	if (wolf->inter_position == VERTICAL)
		wolf->wall_number = (ray_angle >= 270 || ray_angle < 90) ?
							WALL_1 : WALL_2;
	else
		wolf->wall_number = (ray_angle < 180) ? WALL_3 : WALL_4;
	*dist_to_wall = find_line_length(wolf->player.coord, *p_intersect);
	*dist_to_wall *= cos(RADIANS(ray_angle - wolf->player.angle));
}
