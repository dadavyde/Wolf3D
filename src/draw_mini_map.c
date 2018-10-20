/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 21:11:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/10 21:11:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			draw_mini_map(t_wolf3d *sdl)
{
	t_point		start_coord;
	t_point		end_coord;
	uint32_t	color;

	start_coord.y = 0;
	end_coord.x = sdl->map.size.x * sdl->map.blocksize;
	end_coord.y = sdl->map.size.y * sdl->map.blocksize;
	while (start_coord.y < end_coord.y)
	{
		start_coord.x = 0;
		while (start_coord.x < end_coord.x)
		{
			color = find_color_of_square(start_coord,
										sdl->map.blocksize, sdl->map.array);
			draw_square(sdl->screen, start_coord, color,
						sdl->map.blocksize);
			start_coord.x += sdl->map.blocksize;
		}
		start_coord.y += sdl->map.blocksize;
	}
	draw_player_with_rays(sdl);
	return (0);
}

uint32_t	find_color_of_square(t_point start_coord, int mini_map_coef,
			char **map_arr)
{
	uint32_t	color;
	t_point		idx;

	idx.x = start_coord.x / mini_map_coef;
	idx.y = start_coord.y / mini_map_coef;
	color = (map_arr[idx.y][idx.x] != '0') ? 0x555555 : 0xFFFFFF;
	return (color);
}

void		draw_player_with_rays(t_wolf3d *sdl)
{
	t_point		start_coord;

	start_coord.x = ((int)(sdl->player.coord.x / (float)BLOCK_SIZE *
						sdl->map.blocksize)) - PLAYER_RADIUS;
	start_coord.y = ((int)(sdl->player.coord.y / (float)BLOCK_SIZE *
						sdl->map.blocksize)) - PLAYER_RADIUS;
	draw_square(sdl->screen, start_coord, 0xFF0000, PLAYER_RADIUS * 2);
	start_coord.x += PLAYER_RADIUS;
	start_coord.y += PLAYER_RADIUS;
	draw_ray_direction(sdl, start_coord);
}

void		draw_square(SDL_Surface *surface, t_point start_coord,
						uint32_t color, int size)
{
	t_point		end_coord;

	end_coord.x = start_coord.x + size;
	end_coord.y = start_coord.y + size;
	while (start_coord.y < end_coord.y)
	{
		start_coord.x = end_coord.x - size;
		while (start_coord.x < end_coord.x)
		{
			set_pixel(surface, start_coord.x, start_coord.y, color);
			start_coord.x++;
		}
		start_coord.y++;
	}
}

void		draw_ray_direction(t_wolf3d *wolf, t_point start)
{
	t_fpoint	end;
	float		ray_angle;
	int			i;

	i = 0;
	ray_angle = wolf->player.angle + ANGLE_OF_VIEW / 2;
	while (i < NUM_MINI_MAP_RAY)
	{
		recount_float_angle(&ray_angle);
		end = find_closest_intersection(wolf, ray_angle);
		end.x = ((end.x / BLOCK_SIZE * wolf->map.blocksize));
		end.y = ((end.y / BLOCK_SIZE * wolf->map.blocksize));
		draw_line(start, (t_point){(int)end.x, (int)end.y},
				wolf->screen, 0x00FF00);
		ray_angle -= ANGLE_OF_VIEW / NUM_MINI_MAP_RAY;
		i++;
	}
}
