/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finf_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:52:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/09 16:52:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_fpoint	find_closest_intersection(t_wolf3d *sdl, float ray_angle)
{
	float		tan_angle;
	t_fpoint	vertical_p;
	t_fpoint	horizont_p;

	tan_angle = tanf(RADIANS(ray_angle));
	vertical_p = find_vertical_intersection(sdl, tan_angle, ray_angle);
	horizont_p = find_horizontal_intersection(sdl, tan_angle, ray_angle);
	if (find_line_length(sdl->player.coord, vertical_p) <=
		find_line_length(sdl->player.coord, horizont_p))
	{
		sdl->inter_position = VERTICAL;
		return (vertical_p);
	}
	else
	{
		sdl->inter_position = HORIZONTAL;
		return (horizont_p);
	}
}

t_fpoint	find_vertical_intersection(t_wolf3d *sdl, float tan_angle,
										float ray_angle)
{
	float		block_dy;
	int			dx;
	int			direction;
	t_fpoint	test_point;

	if ((fabs(tan_angle) > 1000))
		return ((t_fpoint){10000, 10000});
	block_dy = BLOCK_SIZE * tan_angle;
	direction = (ray_angle > 90 && ray_angle < 270) ? 1 : -1;
	dx = (int)sdl->player.coord.x % BLOCK_SIZE;
	if (direction == -1)
		dx -= BLOCK_SIZE;
	test_point.x = (int)sdl->player.coord.x - dx;
	test_point.y = (int)sdl->player.coord.y + (dx * tan_angle);
	while (test_point.y >= 0 && test_point.y < sdl->map.size.y * BLOCK_SIZE &&
		test_point.x >= 0 && test_point.x < sdl->map.size.x * BLOCK_SIZE &&
		!(is_wall_bound(sdl, test_point, VERTICAL)))
	{
		test_point.x -= BLOCK_SIZE * direction;
		test_point.y += block_dy * direction;
	}
	return (test_point);
}

t_fpoint	find_horizontal_intersection(t_wolf3d *sdl, float tan_angle,
											float ray_angle)
{
	float		block_dx;
	int			dy;
	int			direction;
	t_fpoint	test_point;

	if (tan_angle == 0)
		return ((t_fpoint){10000, 10000});
	direction = (ray_angle <= 180) ? 1 : -1;
	block_dx = (BLOCK_SIZE / tan_angle) * direction;
	dy = (int)sdl->player.coord.y % BLOCK_SIZE;
	dy -= (direction == 1) ? 0 : BLOCK_SIZE;
	test_point.x = ((int)sdl->player.coord.x + dy / tan_angle);
	test_point.y = (int)sdl->player.coord.y - dy;
	while (test_point.x >= 0 && test_point.x < sdl->map.size.x * BLOCK_SIZE &&
		test_point.y >= 0 && test_point.y < sdl->map.size.y * BLOCK_SIZE &&
		!(is_wall_bound(sdl, test_point, HORIZONTAL)))
	{
		test_point.x += block_dx;
		test_point.y -= BLOCK_SIZE * direction;
	}
	return (test_point);
}

int			is_wall_bound(t_wolf3d *sdl, t_fpoint point, int orient)
{
	int		row;
	int		col;

	row = (int)point.y / BLOCK_SIZE;
	col = (int)point.x / BLOCK_SIZE;
	if (orient == HORIZONTAL)
	{
		if ((row - 1 >= 0 && sdl->map.array[row - 1][col] != '0') ||
			(row < sdl->map.size.y && sdl->map.array[row][col] != '0'))
			return (TRUE);
	}
	else
	{
		if ((col - 1 >= 0 && sdl->map.array[row][col - 1] != '0') ||
			(col < sdl->map.size.x && sdl->map.array[row][col] != '0'))
			return (TRUE);
	}
	return (FALSE);
}

float		find_line_length(t_fpoint start, t_fpoint end)
{
	float		len;

	len = (sqrtf((end.x - start.x) * (end.x - start.x) +
				(end.y - start.y) * (end.y - start.y)));
	return (len);
}
