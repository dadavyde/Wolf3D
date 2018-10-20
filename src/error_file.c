/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:45:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/04/06 17:45:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		error_file(void)
{
	ft_putendl("\nInvalid file\n\nusage: ./wolf3d maps/[map_number]\n");
	ft_putendl("for move and rotate use arrows");
	ft_putendl("for change is_texture mode use \"*\"");
	ft_putendl("to display minimap use \"0\"");
	ft_putendl("for stop or play music press space\n");
	return (0);
}
