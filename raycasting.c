/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 16:12:35 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/11/28 17:07:05 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00000000
#define YELLOW 0x00FFFF00

static void	draw_wall(double perpwalldist, t_data *data, int x, int side, int map_x, int map_y)
{
	int wallheight;
	int start;
	int end;
	int	color;

	wallheight = (int)(data->parser.res_height / perpwalldist);
	start = -wallheight / 2 + data->parser.res_height / 2;
	if (start < 0)
		start = 0;
	end = wallheight / 2 + data->parser.res_height / 2;
	if (end >= data->parser.res_height)
		end = data->parser.res_height - 1;
	color = RED;
    if (side == 1) {color = color / 2;}
	for (int i = 0; i < data->parser.res_height; i++)
	{
		if (i < start)
			my_mlx_pixel_put(data->img, x, i, 0x00000000);
		else if (i >= end)
			my_mlx_pixel_put(data->img, x, i, 0x00000000);
		else
			my_mlx_pixel_put(data->img, x, i, 0x00FF0000);
	}	
}

void		omgraycasting(t_data *data, t_mov *mov)
{
	int	x;
	int	map_x;
	int map_y;
	double sidedist_x;
	double sidedist_y;
	double deltadist_x;
	double deltadist_y;
	double perpwalldist;
	int step_x;
	int step_y;
	int hit;
	int side;

	x = 0;
	while (x < data->parser.res_width)
	{
		mov->camera_x = 2 * x / (double)data->parser.res_width - 1;
		mov->raydir_x = mov->dirx + mov->plane_x * mov->camera_x;
		mov->raydir_y = mov->diry + mov->plane_y * mov->camera_x;
		map_x = (int)mov->posx;
		map_y = (int)mov->posy;
		deltadist_x = fabs(1 / mov->raydir_x);
		deltadist_y = fabs(1 / mov->raydir_y);
		hit = 0;
		if (mov->raydir_x < 0)
		{
			step_x = -1;
			sidedist_x = (mov->posx - map_x) * deltadist_x;
		}
		else
		{
			step_x = 1;
			sidedist_x = (map_x + 1.0 - mov->posx) * deltadist_x;
		}
		if (mov->raydir_y < 0)
		{
			step_y = -1;
			sidedist_y = (mov->posy - map_y) * deltadist_y;
		}
		else
		{
			step_y = 1;
			sidedist_y = (map_y + 1.0 - mov->posy) * deltadist_y;
		}
		while (hit == 0)
		{
			if (sidedist_x < sidedist_y)
			{
				sidedist_x += deltadist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				sidedist_y += deltadist_y;
				map_y += step_y;
				side = 1;
			}
			if (data->parser.map.map[map_x][map_y] == '1')
				hit = 1;
		}
		if (side == 0)
			perpwalldist = (map_x - mov->posx + (1 - step_x) / 2) / mov->raydir_x;
		else
			perpwalldist = (map_y - mov->posy + (1 - step_y) / 2) / mov->raydir_y;
		draw_wall(perpwalldist, data, x, side, map_x, map_y);
		x++;
	}
}
