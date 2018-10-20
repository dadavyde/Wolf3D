/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:42:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/07 13:42:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		save_map(char *file, t_wolf3d *sdl)
{
	int		fd;
	char	*line;
	int		idx_y;

	idx_y = 0;
	fd = open(file, O_RDONLY);
	if (!(sdl->map.array = malloc(sizeof(int*) * sdl->map.size.y)))
		return (FALSE);
	while (get_next_line(fd, &line) > 0)
	{
		sdl->map.array[idx_y] = line;
		idx_y++;
	}
	close(fd);
	return (TRUE);
}
