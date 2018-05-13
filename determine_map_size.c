//
// Created by Roman Malkevych on 5/5/18.
//

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/05/05 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	determine_map_size(char *line, t_win *win)
{
	char**	map_size;
	size_t	len;

	map_size = mod_strsplit(line, ' ', &len);
	if (len != 2)
	{
		ft_putstr("Incorrect size of map!\n"); // TODO: use functions for error messages!
		ft_putstr("Put correct map!\n");
	}
	win->map_width = (unsigned int)ft_atoi(map_size[0]);
	win->map_height = (unsigned int)ft_atoi(map_size[1]);
	if (win->map_width < 3 || win->map_height < 3)
	{
		ft_putstr("Minimal size of each side of map is 3!\n"); // TODO: use functions for error messages!
		ft_putstr("Put correct map! - minimal size\n");
		exit(0);
	}
}