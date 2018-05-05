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
		if (worldMap[(int)(win->posX + win->dirX * win->moveSpeed)][(int)win->posY] == 0)
			win->posX += win->dirX * win->moveSpeed;
		if (worldMap[(int)win->posX][(int)(win->posY + win->dirY * win->moveSpeed)] == 0)
			win->posY += win->dirY * win->moveSpeed;
	}
	//move backwards if no wall behind you
	if (keyInput == DOWNKEY)
	{
		if (worldMap[(int)(win->posX - win->dirX * win->moveSpeed)][(int)win->posY] == 0)
			win->posX -= win->dirX * win->moveSpeed;
		if (worldMap[(int)win->posX][(int)(win->posY - win->dirY * win->moveSpeed)] == 0)
			win->posY -= win->dirY * win->moveSpeed;
	}
	//rotate to the right
	if (keyInput == RIGHTKEY)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = win->dirX;
		win->dirX = win->dirX * cos(-win->rotSpeed) - win->dirY * sin(-win->rotSpeed);
		win->dirY = oldDirX * sin(-win->rotSpeed) + win->dirY * cos(-win->rotSpeed);
		double oldPlaneX = win->planeX;
		win->planeX = win->planeX * cos(-win->rotSpeed) - win->planeY * sin(-win->rotSpeed);
		win->planeY = oldPlaneX * sin(-win->rotSpeed) + win->planeY * cos(-win->rotSpeed);
	}
	//rotate to the left
	if (keyInput == LEFTKEY)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = win->dirX;
		win->dirX = win->dirX * cos(win->rotSpeed) - win->dirY * sin(win->rotSpeed);
		win->dirY = oldDirX * sin(win->rotSpeed) + win->dirY * cos(win->rotSpeed);
		double oldPlaneX = win->planeX;
		win->planeX = win->planeX * cos(win->rotSpeed) - win->planeY * sin(win->rotSpeed);
		win->planeY = oldPlaneX * sin(win->rotSpeed) + win->planeY * cos(win->rotSpeed);
	}
	if (keyInput == 53)
		exit(0);
	write_to_image(win);
	return 0;
}