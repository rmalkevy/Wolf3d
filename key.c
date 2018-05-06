/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/05/05 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		my_key_funct(int keyInput, t_win *win) {

	//move forward if no wall in front of you
	printf("KEY %d\n", keyInput);
	if (keyInput == UPKEY)
	{
		if (win->map[(int)(win->cam.posX + win->cam.dirX * win->moveSpeed)][(int)win->cam.posY] == 0)
			win->cam.posX += win->cam.dirX * win->moveSpeed;
		if (win->map[(int)win->cam.posX][(int)(win->cam.posY + win->cam.dirY * win->moveSpeed)] == 0)
			win->cam.posY += win->cam.dirY * win->moveSpeed;
	}
	//move backwards if no wall behind you
	if (keyInput == DOWNKEY)
	{
		if (win->map[(int)(win->cam.posX - win->cam.dirX * win->moveSpeed)][(int)win->cam.posY] == 0)
			win->cam.posX -= win->cam.dirX * win->moveSpeed;
		if (win->map[(int)win->cam.posX][(int)(win->cam.posY - win->cam.dirY * win->moveSpeed)] == 0)
			win->cam.posY -= win->cam.dirY * win->moveSpeed;
	}
	//rotate to the right
	if (keyInput == RIGHTKEY)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = win->cam.dirX;
		win->cam.dirX = win->cam.dirX * cos(-win->rotSpeed) - win->cam.dirY * sin(-win->rotSpeed);
		win->cam.dirY = oldDirX * sin(-win->rotSpeed) + win->cam.dirY * cos(-win->rotSpeed);
		double oldPlaneX = win->cam.planeX;
		win->cam.planeX = win->cam.planeX * cos(-win->rotSpeed) - win->cam.planeY * sin(-win->rotSpeed);
		win->cam.planeY = oldPlaneX * sin(-win->rotSpeed) + win->cam.planeY * cos(-win->rotSpeed);
	}
	//rotate to the left
	if (keyInput == LEFTKEY) {
		//both camera direction and camera plane must be rotated
		double oldDirX = win->cam.dirX;
		win->cam.dirX = win->cam.dirX * cos(win->rotSpeed) - win->cam.dirY * sin(win->rotSpeed);
		win->cam.dirY = oldDirX * sin(win->rotSpeed) + win->cam.dirY * cos(win->rotSpeed);
		double oldPlaneX = win->cam.planeX;
		win->cam.planeX = win->cam.planeX * cos(win->rotSpeed) - win->cam.planeY * sin(win->rotSpeed);
		win->cam.planeY = oldPlaneX * sin(win->rotSpeed) + win->cam.planeY * cos(win->rotSpeed);
	}
	if (keyInput == EXITKEY)
		exit(0);
	write_to_image(win);
	return 0;
}