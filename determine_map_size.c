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

void	fill_map_size(char** map_size, t_win *win)
{
	int i;

	i = 0;
	while (map_size[i])
		++i;
	if (i != 2)
	{
		ft_putstr("Incorrect size of map!\n"); // TODO: use functions for error messages!
		ft_putstr("Put correct map!");
	}
	win->map_width = (unsigned int)ft_atoi(map_size[0]);
	win->map_height = (unsigned int)ft_atoi(map_size[1]);
	if (win->map_width < 3 || win->map_height < 3)
	{
		ft_putstr("Minimal size of each side of map is 3!\n"); // TODO: use functions for error messages!
		ft_putstr("Put correct map!");
		exit(0);
	}
}

void	determine_map_size(char **file_name, t_win *win)
{
	char	*line;
	int		fd;
	int		error;
	char**	map_size;

	line = NULL;
	fd = open(file_name[1], O_RDONLY);
	error = get_next_line(fd, &line);
	close(fd);
	if (error == -1)
	{
		ft_putstr("Put correct map!");
		if (line)
			free(line);
		exit(0);
	}
	map_size = ft_strsplit(line, ' ');
	fill_map_size(map_size, win);
}