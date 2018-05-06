//
// Created by Roman Malkevych on 10/28/17.
//

#ifndef WOLF_WOLF_H
# define WOLF_WOLF_H

# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define UPKEY 126
# define DOWNKEY 125
# define LEFTKEY 123
# define RIGHTKEY 124
# define EXITKEY 53

# define WIDTH_SCREEN 720
# define HEIGHT_SCREEN 480

typedef struct	s_cam
{
	double		cameraX;
	double		posX;
	double		posY;  //x and y start position
	double		dirX;
	double		dirY; //initial direction vector
	double		rayPosX;
	double		rayPosY;
	double		rayDirX;
	double		rayDirY;
	double		planeX;
	double		planeY; //the 2d raycaster version of camera plane
}				t_cam;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*line;
	size_t		color;

	t_cam		cam;
	double		moveSpeed;
	double		rotSpeed;

	size_t		**map;
	size_t		map_width;
	size_t		map_height;
}				t_win;


char			**mod_strsplit(char const *s, char c, size_t *size);

int				error_handler(int ac);
void			determine_map_size(char *map_size, t_win *win);
void			map_handler(char **file_name, t_win *win);

t_win*			win_initialization();
void			put_color_to_pixel(t_win *win, int x, int y);
void			ver_line(int x, int start, int end, t_win *win);
void			write_to_image(t_win *win);
int				my_key_funct(int keyInput, t_win *win);
void			create_image(t_win *win);
void			draw(t_win *win);

#endif
