/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 17:38:21 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/27 13:06:30 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate(t_mov *mov, double rotspd)
{
	double	olddirx;
	double	oldplanex;

	olddirx = mov->dirx;
	mov->dirx = mov->dirx * cos(rotspd) - mov->diry * sin(rotspd);
	mov->diry = olddirx * sin(rotspd) + mov->diry * cos(rotspd);
	oldplanex = mov->plane_x;
	mov->plane_x = mov->plane_x * cos(rotspd) - mov->plane_y * sin(rotspd);
	mov->plane_y = oldplanex * sin(rotspd) + mov->plane_y * cos(rotspd);
}

static void	strafe(t_map *map, double movspd)
{
	int	next_x;
	int	next_y;

	next_x = (int)(map->mov.posx + map->mov.plane_x * movspd * 2);
	next_y = (int)(map->mov.posy + map->mov.plane_y * movspd * 2);
	if (!ft_strchr("12", map->map[next_x][(int)map->mov.posy]))
		map->mov.posx += map->mov.plane_x * movspd;
	if (!ft_strchr("12", map->map[(int)map->mov.posx][next_y]))
		map->mov.posy += map->mov.plane_y * movspd;
}

static void	fwd_back(t_map *map, double movspd)
{
	int	next_x;
	int	next_y;

	next_x = (int)(map->mov.posx + map->mov.dirx * movspd * 2);
	next_y = (int)(map->mov.posy + map->mov.diry * movspd * 2);
	if (!ft_strchr("12", map->map[next_x][(int)map->mov.posy]))
		map->mov.posx += map->mov.dirx * movspd;
	if (!ft_strchr("12", map->map[(int)map->mov.posx][next_y]))
		map->mov.posy += map->mov.diry * movspd;
}

int	detect_movement(t_data *data)
{
	if (data->parser.map.mov.fwd)
		fwd_back(&data->parser.map, MOVSPD);
	if (data->parser.map.mov.back)
		fwd_back(&data->parser.map, -MOVSPD);
	if (data->parser.map.mov.rot_l)
		rotate(&data->parser.map.mov, ROTSPD);
	if (data->parser.map.mov.rot_r)
		rotate(&data->parser.map.mov, -ROTSPD);
	if (data->parser.map.mov.strafe_r)
		strafe(&data->parser.map, MOVSPD);
	if (data->parser.map.mov.strafe_l)
		strafe(&data->parser.map, -MOVSPD);
	omg_raycasting(data, &data->parser.map.mov);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
