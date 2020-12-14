/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 11:43:09 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/12/10 17:32:04 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

/*
**  to fix:
**	-- Free 2d array and strjoin if error
*/

void	detect_movement(t_data *data, t_map *map)
{
	int		next_x;
	int		next_y;
	int		cur_x;
	int		cur_y;
	double	olddirx;
	double	oldplanex;

	cur_x = (int)map->mov.posx;
	cur_y = (int)map->mov.posy;
	next_x = (int)(map->mov.posx + map->mov.dirx * (map->mov.movspd * 2));
	next_y = (int)(map->mov.posy - map->mov.diry * (map->mov.movspd * 2));
	// printf("map_x = %c\n", map->map[next_x][cur_y]);
	if (map->mov.fwd == 1 && map->mov.back != 1)
	{
		if (!ft_strchr("12", map->map[next_x][cur_y]))
			map->mov.posx += map->mov.dirx * map->mov.movspd;
		if (!ft_strchr("12", map->map[cur_x][next_y]))
			map->mov.posy += map->mov.diry * map->mov.movspd;
	}
	if (map->mov.back == 1 && map->mov.fwd != 1)
	{
		if (!ft_strchr("12", map->map[next_x][cur_y]))
			map->mov.posx -= map->mov.dirx * map->mov.movspd;
		if (!ft_strchr("12", map->map[cur_x][next_y]))
			map->mov.posy -= map->mov.diry * map->mov.movspd;
	}
	if (map->mov.rot_l == 1 && map->mov.rot_r != 1)
	{
		olddirx = map->mov.dirx;
		map->mov.dirx = map->mov.dirx * cos(map->mov.rotspd) - map->mov.diry * sin(map->mov.rotspd);
		map->mov.diry = olddirx * sin(map->mov.rotspd) + map->mov.diry * cos(map->mov.rotspd);
		oldplanex = map->mov.plane_x;
		map->mov.plane_x = map->mov.plane_x * cos(map->mov.rotspd) - map->mov.plane_y * sin(map->mov.rotspd);
		map->mov.plane_y = oldplanex * sin(map->mov.rotspd) + map->mov.plane_y * cos(map->mov.rotspd);
	}
	if (map->mov.rot_r == 1 && map->mov.rot_l != 1)
	{
		olddirx = map->mov.dirx;
		map->mov.dirx = map->mov.dirx * cos(-map->mov.rotspd) - map->mov.diry * sin(-map->mov.rotspd);
		map->mov.diry = olddirx * sin(-map->mov.rotspd) + map->mov.diry * cos(-map->mov.rotspd);
		oldplanex = map->mov.plane_x;
		map->mov.plane_x = map->mov.plane_x * cos(-map->mov.rotspd) - map->mov.plane_y * sin(-map->mov.rotspd);
		map->mov.plane_y = oldplanex * sin(-map->mov.rotspd) + map->mov.plane_y * cos(-map->mov.rotspd);
	}
	omgraycasting(data, &map->mov);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	key_release(int keycode, t_data *data)
{
	// printf("Released the key: %i\n", keycode);
	if (keycode == 119)
		data->parser.map.mov.fwd = 0;
	if (keycode == 115)
		data->parser.map.mov.back = 0;
	if (keycode == 97)
		data->parser.map.mov.strafe_l = 0;
	if (keycode == 100)
		data->parser.map.mov.strafe_r = 0;
	if (keycode == 65361)
		data->parser.map.mov.rot_l = 0;
	if (keycode == 65363)
		data->parser.map.mov.rot_r = 0;
	return (0);
}

int	enter_window(int keycode, t_data *data)
{
	// printf("HERRO\n");
	return (0);
}

int	leave_window(int keycode, t_data *data)
{
	// printf("BYE!\n");
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	// printf("Pressed the key: %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
	if (keycode == 119)
		data->parser.map.mov.fwd = 1;
	if (keycode == 115)
		data->parser.map.mov.back = 1;
	if (keycode == 97)
		data->parser.map.mov.strafe_l = 1;
	if (keycode == 100)
		data->parser.map.mov.strafe_r = 1;
	if (keycode == 65361)
		data->parser.map.mov.rot_l = 1;
	if (keycode == 65363)
		data->parser.map.mov.rot_r = 1;
	detect_movement(data, &data->parser.map);
	return (0);
}

int	main(void)
{
	t_data	data;

	parser(&data.parser);
	get_colour(&data.parser);
	data.mlx = mlx_init();
	// if (!data.mlx)
	// {
	// 	ft_printf("Something went horribly fucking wrong\n");
	// 	exit(0);
	// }
	data.mlx_win = mlx_new_window(data.mlx, data.parser.res_width, data.parser.res_height, "Cub3d");
	// if (!data.mlx_win)
	// {
	// 	ft_printf("Something went horribly fucking wrong2\n");
	// 	exit(0);
	// }
	data.img = mlx_new_image(data.mlx, data.parser.res_width, data.parser.res_height);
	// if (!data.img)
	// {
	// 	ft_printf("Something went horribly fucking wrong3\n");
	// 	exit(0);
	// }
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.length, &data.endian);
	// if (!data.addr)
	// {
	// 	ft_printf("Something went horribly fucking wrong4\n");
	// 	exit(0);
	// }
	mlx_do_key_autorepeatoff(data.mlx);
	mlx_do_sync(data.mlx);
	omgraycasting(&data, &data.parser.map.mov);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L<<1, key_release, &data);
	mlx_hook(data.mlx_win, 7, 1L<<4, enter_window, &data);
	mlx_hook(data.mlx_win, 8, 1L<<5, leave_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
