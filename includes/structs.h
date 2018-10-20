/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:44:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/06 15:44:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define NUM_OF_TEXTURES 6

enum	e_textures {SKY, WALL_1, WALL_2, WALL_3, WALL_4, FLOOR};

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

typedef struct		s_fpoint
{
	float		x;
	float		y;
}					t_fpoint;

typedef struct		s_player_data
{
	int				angle;
	t_fpoint		coord;
	int				move;
}					t_player_data;

typedef struct		s_map
{
	t_point			size;
	int				blocksize;
	int				is_map;
	char			**array;
}					t_map;

typedef struct		s_wolf3d
{
	SDL_Window		*window;
	SDL_Surface		*textures[NUM_OF_TEXTURES];
	SDL_Surface		*screen;
	Mix_Music		*music;
	t_player_data	player;
	int				wall_number;
	t_map			map;
	float			dist_to_project_screen;
	float			angle_step;
	int				inter_position;
	int				is_texture;
}					t_wolf3d;

#endif
