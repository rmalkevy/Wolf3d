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
//	clock_t start = 0;
//	clock_t end;

	mlx_clear_window(win->mlx, win->win);
	create_image(win);
	t_cam cam;
	for(int x = 0; x < WIDTH_SCREEN; x++)
	{
		//calculate ray position and direction
		win->cam.cameraX = 2 * x / (double)WIDTH_SCREEN - 1; //x-coordinate in camera space
		cam.rayPosX = win->cam.posX;
		cam.rayPosY = win->cam.posY;
		cam.rayDirX = win->cam.dirX + win->cam.planeX * win->cam.cameraX;
		cam.rayDirY = win->cam.dirY + win->cam.planeY * win->cam.cameraX;
		//which box of the map we're in
		int mapX = (int)cam.rayPosX;
		int mapY = (int)cam.rayPosY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / cam.rayDirX);
		double deltaDistY = fabs(1 / cam.rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side = 0; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (cam.rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cam.rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cam.rayPosX) * deltaDistX;
		}
		if (cam.rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cam.rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cam.rayPosY) * deltaDistY;
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
			if (win->map[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - cam.rayPosX + (1 - stepX) / 2) / cam.rayDirX;
		else
			perpWallDist = (mapY - cam.rayPosY + (1 - stepY) / 2) / cam.rayDirY;

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
		switch(win->map[mapX][mapY])
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
		win->color = 0x269900;
		ver_line(x, 0, drawStart, win);
		win->color = 0x800000;
		ver_line(x, drawEnd, HEIGHT_SCREEN, win);
	}
	//timing for input and FPS counter
//		oldTime = time;
//		time = get;
//	end = start;
//	start = clock();
//	double frameTime = (double)(start - end) / CLOCKS_PER_SEC; //frameTime is the time this frame has taken, in seconds

//	//speed modifiers
	win->moveSpeed = 0.2; //the constant value is in squares/second
	win->rotSpeed = 0.1; //the constant value is in radians/second

	mlx_destroy_image(win->mlx, win->image);
}

void	set_player(t_win *win)
{
	size_t	height;
	size_t	width;
	int		breaker;

	height = 2;
	breaker = 0;
	while (height < win->map_height)
	{
		width = 2;
		while (width < win->map_width)
		{
			if (win->map[height][width] == 0)
			{
				win->cam.posX = height;
				win->cam.posY = width;
				breaker = 1;
				break ;
			}
			++width;
		}
		if (breaker == 1)
			break ;
		++height;
	}
	if (!breaker)
	{
		ft_putstr("No place for set position for player\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	if (error_handler(argc))
	{
		t_win *win = win_initialization();
		map_handler(argv, win);
		set_player(win);
		write_to_image(win);
	}
	return (1);
}