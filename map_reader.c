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
	size_t i;

	i = 0;
	splited_line = mod_strsplit(line, ',', &i);
	if (i != win->map_width)
	{
		ft_putstr("Not correct size of the map line N");
		ft_putnbr((int)i);
		exit(0);
	}
	i = 0;
	win->map = (size_t**)malloc(sizeof(size_t*) * win->map_height);
	while (i < win->map_width)
	{
		win->map[num_line][i] = (size_t)ft_atoi(splited_line[i]);
		i++;
	}
}

void	create_map(char** map, t_win *win)
{
	size_t i;

	i = 0;
	while(map[i])
	{
		handle_line_of_map(map[i], win, i);
		i++;
	}
}

void	map_reader(char** file_name, t_win *win)
{
	char	*line;
	char	**map;
	int		len;
	int		fd;
	int		error;

	len = 0;
	line = NULL;
	map = (char**)malloc(sizeof(char*) * (win->map_height + 2));
	fd = open(file_name[1], O_RDONLY);
	while ((error = get_next_line(fd, &line) > 0) && error != -1)
	{
		map[len++] = ft_strdup(line);
		// TODO: check if line is not make memory leaks
	}
	if (error == -1)
	{
		ft_putstr("Put correct map!");
		exit(0);
	}
	create_map(map, win);
}

// TODO: Later - transfer this code to the main.c
void	map_handler(char **file_name, t_win *win)
{
	determine_map_size(file_name, win);
	map_reader(file_name, win);
}











//
//t_str	*create_str(char **map, int len)
//{
//	t_str	*str;
//	int		i;
//	int		j;
//
//	i = -1;
//	j = 0;
//	if (!(str = (t_str*)malloc(sizeof(t_str) * (len + 1))))
//		return (0);
//	while (++i < len)
//		str[i].line = ft_strsplit(map[i], ' ');
//	str->y_len = len;
//	i = 0;
//	while (str[j].line[i])
//		i++;
//	str->x_len = i;
//	return (str);
//}
