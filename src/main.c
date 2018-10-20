/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:08:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/06 16:08:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_wolf3d	wolf;

	ft_bzero(&wolf, sizeof(t_wolf3d));
	if (argc != 2)
		return (error_file());
	else
	{
		if (!validate(argv[1], &wolf))
			return (error_file());
		if (!save_map(argv[1], &wolf))
			return (error_file());
		if (init(&wolf) == FALSE)
			return (0);
		play_wolf3d(&wolf);
	}
	return (0);
}
