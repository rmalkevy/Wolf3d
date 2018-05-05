/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/05/05 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    draw(t_win *win)
{
	clock_t start = 0;
	clock_t end;
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	mlx_clear_window(win->mlx, win->win);
	create_image(win);
	for(int x = 0; x < WIDTH_SCREEN; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)WIDTH_SCREEN - 1; //x-coordinate in camera space
		double rayPosX = win->posX;
		double rayPosY = win->posY;
		double rayDirX = win->dirX + win->planeX * cameraX;
		double rayDirY = win->dirY + win->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)rayPosX;
		int mapY = (int)rayPosY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side = 0; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT_SCREEN / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT_SCREEN / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT_SCREEN / 2;
		if (drawEnd >= HEIGHT_SCREEN)
			drawEnd = HEIGHT_SCREEN - 1;

		//choose wall color
		//unsigned int color = 0xFFFFFF;
		switch(worldMap[mapX][mapY])
		{
			case 1:  win->color = 0x00FFFF;  break; //red
			case 2:  win->color = 0x0000FF;  break; //green
			case 3:  win->color = 0xFF0000;   break; //blue
			case 4:  win->color = 0xFFFF00;  break; //white
			default: win->color = 0xFFFFFF; break; //yellow
		}

		//give x and y sides different brightness
		if (side == 1)
		{
			win->color = win->color / 2;
		}
		//draw the pixels of the stripe as a vertical line
		ver_line(x, drawStart, drawEnd, win);
	}
	//timing for input and FPS counter
//		oldTime = time;
//		time = get;
	end = start;
	start = clock();
	double frameTime = (double)(start - end) / CLOCKS_PER_SEC; //frameTime is the time this frame has taken, in seconds
	printf("FrameTime %f\n", frameTime);

//	//speed modifiers
	win->moveSpeed = 0.2; //the constant value is in squares/second
	win->rotSpeed = 0.1; //the constant value is in radians/second

	mlx_destroy_image(win->mlx, win->image);
}

int main(int argc, char *argv[])
{
	if (error_handler(argc))
	{
		t_win *win = win_initialization();
		map_handler(argv, win);
		write_to_image(win);
	}
}