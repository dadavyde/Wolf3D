/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:43:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/06 15:43:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL.h>
# include <SDL_mixer.h>
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "structs.h"

# define FALSE 0
# define TRUE 1
# define MIN_MAP_SIZE 3
# define PLAYER_ANGLE 0
# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000
# define BLOCK_SIZE 64
# define PLAYER_SPEED 5
# define ANGLE_OF_VIEW 60
# define ANGLE_SHIFT 5
# define W_TITLE "Wolf3D by dadavyde"
# define HORIZONTAL 0
# define VERTICAL 1
# define RADIANS(angle) (M_PI * (angle) / 180.0)
# define NUM_MINI_MAP_RAY 60
# define PLAYER_RADIUS 5

/*
**	error_file.c
*/

int			error_file(void);

/*
**	validate.c
*/

int			validate(char *file, t_wolf3d *sdl);
int			find_map_sizes(char *file, t_wolf3d *sdl);
int			check_line(int fd, t_wolf3d *sdl);
int			check_for_zero(char *line, t_wolf3d *sdl, int idx_y);

/*
**	save_map.c
*/

int			save_map(char *file, t_wolf3d *sdl);

/*
**	init.c
*/

int			init(t_wolf3d *sdl);
int			set_texture(t_wolf3d *sdl, char *way_to_textures, int texture_name);
void		set_pixel(SDL_Surface *surface, int x, int y, uint32_t color);
uint32_t	get_pixel(SDL_Surface *surface, int x, int y);

/*
**	recount_angle.c
*/

void		recount_float_angle(float *f_angle);
void		recount_int_angle(int *i_angle);

/*
**	play_wolf3d.c
*/

int			play_wolf3d(t_wolf3d *sdl);
int			update_image(t_wolf3d *sdl, int keycode);
void		player_move(t_wolf3d *sdl);
int			is_wall(t_wolf3d *sdl, int x, int y, int is_x);

/*
**	events.c
*/

int			events(t_wolf3d *sdl, SDL_Event *event);
int			play_music(t_wolf3d *sdl);
int			key_down(t_wolf3d *sdl, SDL_Event *event);
int			event_music(t_wolf3d *sdl, SDL_Event *event);
int			exit_x(t_wolf3d *sdl, SDL_Event *event, int flag);

/*
**	draw_scene.c
*/

int			draw_scene(t_wolf3d *sdl);
int			draw_ray(t_wolf3d *wolf, int x, float ray_angle);
void		set_some_param(t_wolf3d *wolf, t_fpoint *p_intersect,
						float ray_angle, float *dist_to_wall);

/*
**	draw_texture_scene.c
*/

void		draw_sky(t_wolf3d *wolf, int ceil_h, int x, float ray_angle);
void		draw_texture_walls(t_wolf3d *wolf, int ceil_h, int x,
								t_fpoint p_intersect);
void		texture_set_param(t_wolf3d *wolf, t_fpoint p_intersect,
							t_fpoint *texture, int wall_h);
void		draw_texture_floor(t_wolf3d *wolf, int ceil_h, int x,
								float ray_angle);
t_point		get_floor_texture_coord(t_wolf3d *wolf, float dist_to_floor,
										float ray_angle);

/*
**	draw_solid_scene.c
*/

void		draw_4_col_walls(t_wolf3d *sdl, int ceil_h, float ray_angle, int x);
void		draw_1_col_floor_and_sky(t_wolf3d *sdl, int ceil_h, int x);

/*
**	find_intersection.c
*/

t_fpoint	find_closest_intersection(t_wolf3d *sdl, float ray_angle);
t_fpoint	find_vertical_intersection(t_wolf3d *sdl, float tan_angle,
										float ray_angle);
t_fpoint	find_horizontal_intersection(t_wolf3d *sdl, float tan_angle,
										float ray_angle);
int			is_wall_bound(t_wolf3d *sdl, t_fpoint point, int orient);
float		find_line_length(t_fpoint start, t_fpoint end);

/*
**	draw_mini_map.c
*/

int			draw_mini_map(t_wolf3d *sdl);
uint32_t	find_color_of_square(t_point start_coord, int mini_map_coef,
								char **map_arr);
void		draw_player_with_rays(t_wolf3d *sdl);
void		draw_square(SDL_Surface *surface, t_point start_coord,
						uint32_t color, int size);
void		draw_ray_direction(t_wolf3d *wolf, t_point start);

/*
**	draw_line.c
*/

void		draw_line(t_point start, t_point end, SDL_Surface *surface,
					unsigned int color);

#endif
