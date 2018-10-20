/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:33:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/06/16 17:04:39 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		events(t_wolf3d *sdl, SDL_Event *event)
{
	int			running;
	int			flag;

	running = TRUE;
	flag = FALSE;
	if (play_music(sdl) == FALSE)
		flag = TRUE;
	while (running)
	{
		while (SDL_PollEvent(event))
		{
			if (!exit_x(sdl, event, flag))
				running = FALSE;
			if (event->type == SDL_KEYDOWN)
				key_down(sdl, event);
		}
	}
	return (0);
}

int		key_down(t_wolf3d *sdl, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_UP)
		sdl->player.move = PLAYER_SPEED;
	else if (event->key.keysym.sym == SDLK_DOWN)
		sdl->player.move = -PLAYER_SPEED;
	else if (event->key.keysym.sym == SDLK_RIGHT)
		sdl->player.angle -= ANGLE_SHIFT;
	else if (event->key.keysym.sym == SDLK_LEFT)
		sdl->player.angle += ANGLE_SHIFT;
	else if (event->key.keysym.sym == SDLK_KP_MULTIPLY)
		sdl->is_texture = (sdl->is_texture + 1) % 2;
	else if (event->key.keysym.sym == SDLK_KP_0)
		sdl->map.is_map = ~sdl->map.is_map;
	else if (event->key.keysym.sym == SDLK_SPACE ||
		event->key.keysym.sym == SDLK_DELETE)
		return (event_music(sdl, event));
	else
		return (0);
	update_image(sdl, event->key.keysym.sym);
	return (0);
}

int		play_music(t_wolf3d *sdl)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ft_putendl("SDL_mixer could not initialize! SDL_mixer Error: ");
		ft_putendl(Mix_GetError());
		ft_putendl("\n");
		return (FALSE);
	}
	sdl->music = Mix_LoadMUS("textures/music.wav");
	if (sdl->music == NULL)
	{
		ft_putendl("Failed to load beat music! SDL_mixer Error: ");
		ft_putendl(Mix_GetError());
		ft_putendl("\n");
		return (FALSE);
	}
	Mix_PlayMusic(sdl->music, -1);
	return (TRUE);
}

int		event_music(t_wolf3d *sdl, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_SPACE)
	{
		if (Mix_PlayingMusic() == FALSE)
			Mix_PlayMusic(sdl->music, -1);
		else
		{
			if (Mix_PausedMusic() == TRUE)
				Mix_ResumeMusic();
			else
				Mix_PauseMusic();
		}
	}
	else if (event->key.keysym.sym == SDLK_DELETE)
		Mix_HaltMusic();
	return (0);
}

int		exit_x(t_wolf3d *sdl, SDL_Event *event, int flag)
{
	if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN &&
		event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) || flag)
	{
		Mix_FreeMusic(sdl->music);
		SDL_FreeSurface(sdl->screen);
		SDL_FreeSurface(sdl->textures[SKY]);
		SDL_FreeSurface(sdl->textures[WALL_1]);
		SDL_FreeSurface(sdl->textures[WALL_2]);
		SDL_FreeSurface(sdl->textures[WALL_3]);
		SDL_FreeSurface(sdl->textures[WALL_4]);
		SDL_FreeSurface(sdl->textures[FLOOR]);
		SDL_DestroyWindow(sdl->window);
		Mix_Quit();
		SDL_Quit();
		return (FALSE);
	}
	else
		return (TRUE);
}
