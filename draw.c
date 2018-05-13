/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/05/05 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_color_to_pixel(t_win *win, int x, int y)
{
	int pixel;

	pixel = (x + y * WIDTH_SCREEN) * 4;
	win->line[pixel + 0] = (unsigned char)((win->color >> 16) & 0xFF);
	win->line[pixel + 1] = (unsigned char)((win->color >> 8) & 0xFF);
	win->line[pixel + 2] = (unsigned char)(win->color & 0xFF);
}

void ver_line(int x, int draw_start, int draw_end, t_win *win)
{
	while (draw_start < draw_end)
	{
		put_color_to_pixel(win, x, draw_start);
		draw_start++;
	}
}