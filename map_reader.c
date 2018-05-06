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

int		error_handler(int ac)
{
	if (ac == 2)
		return (1);
	else
		return (0);
}

void handle_line_of_map(char* line, t_win *win, size_t num_line)
{
	char** splited_line;
	size_t elems;
	size_t i;

	elems = 0;
	i = 0;
	splited_line = mod_strsplit(line, ',', &elems);
	if (elems != win->map_width)
	{
		ft_putstr("Not correct width of the map - line N");
		ft_putnbr((int)num_line);
		// TODO: free allocated memory;
		exit(0);
	}
	win->map[num_line] = (size_t*)malloc(sizeof(size_t) * win->map_width);
	while (i < win->map_width)
	{
		win->map[num_line][i] = (size_t)ft_atoi(splited_line[i]);
		i++;
	}
}

void	create_map(char** map, t_win *win)
{
	size_t i;

	i = 1;
	win->map = (size_t**)malloc(sizeof(size_t*) * win->map_height);
	while(i < win->map_height + 1)
	{
		handle_line_of_map(map[i], win, i - 1);
		i++;
	}
}

char*	map_reader(char **file_name, t_win *win)
{
	char	dest[BUFF_SIZE + 1];
	char	*line;
	int		fd;
	int		size;

	line = ft_strnew(1);
	fd = open(file_name[1], O_RDONLY);
	while ((size = read(fd, dest, BUFF_SIZE)) && size != -1)
	{
		dest[size] = '\0';
		line = ft_join(line, ft_strdup(dest));
	}
	return (line);
}

// TODO: Later - transfer this code to the main.c
void	map_handler(char **file_name, t_win *win)
{
	char	*line;
	char	**map;

	line = map_reader(file_name, win);
	map = ft_strsplit(line, '\n');
	determine_map_size(map[0], win);
	create_map(map, win);
}

