/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/05/05 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_win*	win_initialization()
{
	t_win *win = (t_win*)malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH_SCREEN, HEIGHT_SCREEN, "Wolf3D");

	win->cam.posX = 22;	// TODO: change start position to map size;
	win->cam.posY = 12;  //x and y start position
	win->cam.dirX = 1;
	win->cam.dirY = 0; //initial direction vector
	win->cam.planeX = 0;
	win->cam.planeY = 0.66; //the 2d raycaster version of camera plane
	return win;
}

void	create_image(t_win *win)
{
	int a[3];

	win->image = mlx_new_image(win->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
	win->line = mlx_get_data_addr(win->image, &a[0], &a[1], &a[2]);
}

void	write_to_image(t_win *win)
{
	mlx_clear_window(win->mlx, win->win);
	create_image(win);

	draw(win);

	mlx_put_image_to_window(win->mlx, win->win, win->image, 0, 0);
	mlx_hook(win->win, 2, 5, my_key_funct, win);
	mlx_hook(win->win, 17, 0, window_destroyed_hook, win);
	mlx_loop(win->mlx);
}