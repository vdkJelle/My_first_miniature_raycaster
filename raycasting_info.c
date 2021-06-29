/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_info.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 11:01:01 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/27 16:06:25 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_sidedist(t_mov *mov, t_ray *ray)
{
	if (mov->raydir_x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (mov->posx - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - mov->posx) * ray->deltadist.x;
	}
	if (mov->raydir_y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (mov->posy - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - mov->posy) * ray->deltadist.y;
	}
}

void	find_intersect(t_ray *ray, t_mov *mov, char **map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			mov->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			mov->side = 1;
		}
		if (map[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
		if (map[ray->map.x][ray->map.y] == '2')
			add_sprite(&mov->sprite, ray->map.x, ray->map.y, mov);
	}
}

void	initialize_values(t_ray *ray, t_mov *mov, int res_width)
{
	mov->camera_x = 2 * mov->x / (double)res_width - 1;
	mov->raydir_x = mov->dirx + mov->plane_x * mov->camera_x;
	mov->raydir_y = mov->diry + mov->plane_y * mov->camera_x;
	ray->map.x = (int)mov->posx;
	ray->map.y = (int)mov->posy;
	ray->deltadist.x = fabs(1 / mov->raydir_x);
	ray->deltadist.y = fabs(1 / mov->raydir_y);
	find_sidedist(mov, ray);
}

void	get_draw_info(t_draw *draw, double perpwalldist,
						t_texture texture[4], t_mov mov)
{
	double	wallx;

	if (mov.side == 0 && mov.raydir_x > 0)
		draw->tx = 2;
	else if (mov.side == 1 && mov.raydir_y > 0)
		draw->tx = 1;
	else if (mov.side == 1 && mov.raydir_y < 0)
		draw->tx = 3;
	if (mov.side == 0)
		wallx = mov.posy + perpwalldist * mov.raydir_y;
	else
		wallx = mov.posx + perpwalldist * mov.raydir_x;
	wallx -= floor(wallx);
	draw->row = (int)(wallx * texture[draw->tx].width);
	if (mov.side == 0 && mov.raydir_x > 0)
		draw->row = texture[draw->tx].width - draw->row - 1;
	if (mov.side == 1 && mov.raydir_y < 0)
		draw->row = texture[draw->tx].width - draw->row - 1;
}
