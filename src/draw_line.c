/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:39:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/12 21:39:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	set_param(t_point *delta, t_point *dir, t_point *start,
						t_point *end)
{
	int		xy_swap;

	if (ABS(end->y - start->y) < ABS(end->x - start->x))
		xy_swap = 0;
	else
	{
		*start = (t_point){start->y, start->x};
		*end = (t_point){end->y, end->x};
		xy_swap = 1;
	}
	delta->x = ABS(end->x - start->x);
	delta->y = ABS(end->y - start->y);
	dir->y = (end->y > start->y) ? 1 : -1;
	dir->x = (end->x > start->x) ? 1 : -1;
	return (xy_swap);
}

static int	check_dot(int x, int y, SDL_Surface *surface)
{
	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
		return (1);
	else
		return (0);
}

void		draw_line(t_point start, t_point end, SDL_Surface *surface,
					unsigned int color)
{
	int			error;
	t_point		dir;
	t_point		delta;
	int			xy_swap;

	error = 0;
	xy_swap = set_param(&delta, &dir, &start, &end);
	while (start.x != end.x)
	{
		if (xy_swap && check_dot(start.x, start.y, surface))
			set_pixel(surface, start.y, start.x, color);
		else if (!xy_swap && check_dot(start.x, start.y, surface))
			set_pixel(surface, start.x, start.y, color);
		error += delta.y;
		if (2 * error >= delta.x)
		{
			start.y += dir.y;
			error -= delta.x;
		}
		start.x += dir.x;
	}
}
