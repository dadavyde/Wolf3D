/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:09:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/07 17:09:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		play_wolf3d(t_wolf3d *sdl)
{
	SDL_Event	event;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_AUDIO);
	sdl->window = SDL_CreateWindow(W_TITLE, SDL_WINDOWPOS_UNDEFINED,
							SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH,
							WIN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	sdl->screen = SDL_GetWindowSurface(sdl->window);
	draw_scene(sdl);
	SDL_UpdateWindowSurface(sdl->window);
	events(sdl, &event);
	return (0);
}

int		update_image(t_wolf3d *sdl, int keycode)
{
	if (keycode == SDLK_UP || keycode == SDLK_DOWN
		|| keycode == SDLK_RIGHT || keycode == SDLK_LEFT
		|| keycode == SDLK_PAGEDOWN || keycode == SDLK_PAGEUP
		|| keycode == SDLK_KP_MULTIPLY || keycode == SDLK_KP_0)
	{
		if (keycode == SDLK_UP || keycode == SDLK_DOWN)
			player_move(sdl);
		draw_scene(sdl);
		if (sdl->map.is_map)
			draw_mini_map(sdl);
		SDL_UpdateWindowSurface(sdl->window);
	}
	return (0);
}

void	player_move(t_wolf3d *sdl)
{
	float		new_x;
	float		new_y;

	new_x = (sdl->player.coord.x + (float)sdl->player.move *
			cosf(RADIANS(sdl->player.angle)));
	new_y = (sdl->player.coord.y + (float)sdl->player.move *
			-sinf(RADIANS(sdl->player.angle)));
	if (!is_wall(sdl, (int)new_x, (int)sdl->player.coord.y, TRUE))
		sdl->player.coord.x = (int)new_x;
	if (!is_wall(sdl, (int)sdl->player.coord.x, (int)new_y, FALSE))
		sdl->player.coord.y = (int)new_y;
}

int		is_wall(t_wolf3d *sdl, int x, int y, int is_x)
{
	int		direction;

	direction = sdl->player.move / PLAYER_SPEED;
	if (is_x)
	{
		x += (direction * PLAYER_RADIUS * 2 * ((sdl->player.angle < 90 ||
				sdl->player.angle > 270) ? 1 : -1));
		if ((sdl->map.array[(y + PLAYER_RADIUS * 2) / BLOCK_SIZE]
			[x / BLOCK_SIZE] == '0') &&
			(sdl->map.array[(y - PLAYER_RADIUS * 2) / BLOCK_SIZE]
			[x / BLOCK_SIZE] == '0'))
			return (FALSE);
	}
	else
	{
		y += (direction * PLAYER_RADIUS * 2 *
				((sdl->player.angle > 180) ? 1 : -1));
		if ((sdl->map.array[y / BLOCK_SIZE][(x + PLAYER_RADIUS * 2) /
											BLOCK_SIZE] == '0') &&
			(sdl->map.array[y / BLOCK_SIZE][(x - PLAYER_RADIUS * 2) /
											BLOCK_SIZE] == '0'))
			return (FALSE);
	}
	return (TRUE);
}
