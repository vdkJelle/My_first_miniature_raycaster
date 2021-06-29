/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 16:12:35 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/03/02 14:21:15 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall(t_data *data, int x, int i, t_draw *draw)
{
	draw->double_col += draw->step;
	draw->col = (int)draw->double_col;
	if (draw->col >= data->texture[draw->tx].height)
		draw->col = data->texture[draw->tx].height - 1;
	draw->colour = my_mlx_get_pixel(data->texture[draw->tx],
			draw->row, draw->col);
	my_mlx_pixel_put(data, x, i, draw->colour);
}

static void	draw_x(double perpwalldist, t_data *data, t_mov *mov)
{
	t_draw	draw;

	ft_bzero(&draw, sizeof(draw));
	get_draw_info(&draw, perpwalldist, data->texture, data->parser.map.mov);
	draw.height = (int)(data->parser.res_height / perpwalldist);
	draw.start = -draw.height / 2 + data->parser.res_height / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = draw.height / 2 + data->parser.res_height / 2;
	if (draw.end >= data->parser.res_height)
		draw.end = data->parser.res_height;
	draw.step = 1.0 * data->texture[draw.tx].height / draw.height;
	draw.double_col = (draw.start - data->parser.res_height / 2
			+ draw.height / 2) * draw.step;
	draw.i = 0;
	while (draw.i < data->parser.res_height)
	{
		if (draw.i < draw.start)
			my_mlx_pixel_put(data, mov->x, draw.i, data->parser.trgb_ceil);
		else if (draw.i >= draw.end)
			my_mlx_pixel_put(data, mov->x, draw.i, data->parser.trgb_floor);
		else
			draw_wall(data, mov->x, draw.i, &draw);
		draw.i++;
	}
}

void	omg_raycasting(t_data *data, t_mov *mov)
{
	t_ray	ray;

	mov->x = 0;
	mov->sprite.vis = 0;
	ft_bzero(mov->sprite.loc, sizeof(t_pos) * mov->sprite.num);
	while (mov->x < data->parser.res_width)
	{
		initialize_values(&ray, mov, data->parser.res_width);
		find_intersect(&ray, mov, data->parser.map.map);
		if (mov->side == 0)
			ray.perpwalldist = (ray.map.x - mov->posx
					+ (1 - ray.step.x) / 2) / mov->raydir_x;
		else
			ray.perpwalldist = (ray.map.y - mov->posy
					+ (1 - ray.step.y) / 2) / mov->raydir_y;
		draw_x(ray.perpwalldist, data, mov);
		mov->sprite.zbuf[mov->x] = ray.perpwalldist;
		mov->x++;
	}
	if (mov->sprite.vis > 0)
	{
		sort_sprites(&mov->sprite, mov->sprite.vis);
		omg_spritescasting(data, mov);
	}
}
