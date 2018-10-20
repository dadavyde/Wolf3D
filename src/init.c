/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:06:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/07 16:06:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			init(t_wolf3d *sdl)
{
	int		flag;

	sdl->is_texture = 0;
	sdl->map.is_map = 0;
	sdl->player.angle = PLAYER_ANGLE;
	sdl->dist_to_project_screen = (float)WIN_WIDTH / 2 /
									tanf(RADIANS(ANGLE_OF_VIEW / 2));
	sdl->player.coord.x = (int)((sdl->player.coord.x + 0.5) * BLOCK_SIZE);
	sdl->player.coord.y = (int)((sdl->player.coord.y + 0.5) * BLOCK_SIZE);
	sdl->angle_step = ((float)ANGLE_OF_VIEW / (float)WIN_WIDTH);
	sdl->map.blocksize =
		(WIN_WIDTH / sdl->map.size.x < WIN_HEIGHT / sdl->map.size.y) ?
		(WIN_WIDTH / sdl->map.size.x / 2) : (WIN_HEIGHT / sdl->map.size.y / 2);
	flag = 0;
	flag += set_texture(sdl, "textures/2_sky.bmp", SKY);
	flag += set_texture(sdl, "textures/wall_strange_2_1920.bmp", WALL_1);
	flag += set_texture(sdl, "textures/wall_eyes_1200_little.bmp", WALL_2);
	flag += set_texture(sdl, "textures/wall_eye_4_1280.bmp", WALL_3);
	flag += set_texture(sdl, "textures/wall_strange_1_1280.bmp", WALL_4);
	flag += set_texture(sdl, "textures/floor_1.bmp", FLOOR);
	if (flag < NUM_OF_TEXTURES)
		return (FALSE);
	return (TRUE);
}

int			set_texture(t_wolf3d *sdl, char *way_to_textures, int texture_name)
{
	SDL_Surface		*tmp;

	tmp = SDL_LoadBMP(way_to_textures);
	if (tmp == NULL)
	{
		ft_putstr("Unable to load image ");
		ft_putendl(way_to_textures);
		ft_putstr("SDL Error: ");
		ft_putendl(SDL_GetError());
		return (FALSE);
	}
	sdl->textures[texture_name] = SDL_ConvertSurfaceFormat(tmp,
									SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(tmp);
	return (TRUE);
}

void		set_pixel(SDL_Surface *surface, int x, int y, uint32_t color)
{
	((uint32_t*)surface->pixels)[y * surface->w + x] = color;
}

uint32_t	get_pixel(SDL_Surface *surface, int x, int y)
{
	return (((uint32_t*)surface->pixels)[y * surface->w + x]);
}
