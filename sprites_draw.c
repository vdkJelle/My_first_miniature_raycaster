/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_draw.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 16:15:42 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/25 12:39:19 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sprites(t_draw_sprite *draw, t_data *data, t_sprite sprite)
{
	draw->x = draw->start_x;
	while (draw->x < draw->end_x)
	{
		draw->col = (int)(256 * (draw->x - (-draw->width / 2
						+ draw->spritescreen_x)) * data->texture[4].width
				/ draw->width) / 256;
		if (draw->transform_y > 0 && draw->x > 0
			&& draw->x < data->parser.res_width
			&& draw->transform_y < sprite.zbuf[draw->x])
		{
			draw->y = draw->start_y;
			while (draw->y < draw->end_y)
			{
				draw->d = draw->y * 256 - data->parser.res_height * 128
					+ draw->height * 128;
				draw->row = ((draw->d * data->texture[4].height)
						/ draw->height) / 256;
				draw->colour = my_mlx_get_pixel(data->texture[4],
						draw->col, draw->row);
				my_mlx_pixel_put(data, draw->x, draw->y, draw->colour);
				draw->y++;
			}
		}
		draw->x++;
	}
}

static void	get_sprite_draw_info(t_draw_sprite *draw, t_data *data, t_mov *mov)
{
	draw->sprite_x = mov->sprite.loc[draw->i].x - mov->posx + 0.5;
	draw->sprite_y = mov->sprite.loc[draw->i].y - mov->posy + 0.5;
	draw->inv = 1.0 / (mov->plane_x * mov->diry - mov->dirx * mov->plane_y);
	draw->transform_x = draw->inv * (mov->diry * draw->sprite_x - mov->dirx
			* draw->sprite_y);
	draw->transform_y = draw->inv * (-mov->plane_y * draw->sprite_x
			+ mov->plane_x * draw->sprite_y);
	draw->spritescreen_x = (int)((data->parser.res_width / 2)
			* (1 + draw->transform_x / draw->transform_y));
	draw->height = abs((int)(data->parser.res_height / draw->transform_y));
	draw->start_y = -draw->height / 2 + data->parser.res_height / 2;
	if (draw->start_y < 0)
		draw->start_y = 0;
	draw->end_y = draw->height / 2 + data->parser.res_height / 2;
	if (draw->end_y >= data->parser.res_height)
		draw->end_y = data->parser.res_height;
	draw->width = draw->height;
	draw->start_x = -draw->width / 2 + draw->spritescreen_x;
	if (draw->start_x < 0)
		draw->start_x = 0;
	draw->end_x = draw->width / 2 + draw->spritescreen_x;
	if (draw->end_x >= data->parser.res_width)
		draw->end_x = data->parser.res_width - 1;
}

void	omg_spritescasting(t_data *data, t_mov *mov)
{
	t_draw_sprite	draw;
	int				i;

	draw.i = 0;
	while (draw.i < mov->sprite.vis)
	{
		i = draw.i;
		ft_bzero(&draw, sizeof(draw));
		draw.i = i;
		get_sprite_draw_info(&draw, data, mov);
		draw_sprites(&draw, data, mov->sprite);
		draw.i++;
	}
}
