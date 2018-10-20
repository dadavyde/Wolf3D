/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:30:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/06 19:30:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		validate(char *file, t_wolf3d *sdl)
{
	int		fd;

	if (!find_map_sizes(file, sdl))
		return (FALSE);
	fd = open(file, O_RDONLY);
	if (!check_line(fd, sdl))
		return (FALSE);
	close(fd);
	return (TRUE);
}

int		find_map_sizes(char *file, t_wolf3d *sdl)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	while (get_next_line(fd, &line) > 0)
	{
		if (!sdl->map.size.y)
			sdl->map.size.x = (int)ft_strlen(line);
		free(line);
		sdl->map.size.y++;
	}
	if (get_next_line(fd, &line) == -1 || sdl->map.size.x < MIN_MAP_SIZE ||
										sdl->map.size.y < MIN_MAP_SIZE)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int		check_line(int fd, t_wolf3d *sdl)
{
	char	*line;
	int		idx_y;

	idx_y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((int)ft_strlen(line) != sdl->map.size.x || !ft_isnumber(line, 0) ||
			!check_for_zero(line, sdl, idx_y))
			return (FALSE);
		free(line);
		idx_y++;
	}
	return (sdl->player.coord.x ? TRUE : FALSE);
}

int		check_for_zero(char *line, t_wolf3d *sdl, int idx_y)
{
	int		idx_x;

	idx_x = 0;
	while (line[idx_x])
	{
		if (idx_x == 0 || idx_x == sdl->map.size.x - 1)
		{
			if (idx_y > 0 && idx_y < sdl->map.size.y - 1 && line[idx_x] == '0')
				return (FALSE);
		}
		else
		{
			if (idx_y > 0 && idx_y < sdl->map.size.y - 1)
			{
				if (line[idx_x] == '0' && !(sdl->player.coord.x))
					sdl->player.coord = (t_fpoint){idx_x, idx_y};
			}
			else if (line[idx_x] == '0')
				return (FALSE);
		}
		idx_x++;
	}
	return (TRUE);
}
