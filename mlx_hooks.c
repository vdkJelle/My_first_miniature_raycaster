/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 20:36:27 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/04 13:12:11 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cross(void)
{
	exit (0);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->parser.map.mov.fwd = 0;
	if (keycode == 1)
		data->parser.map.mov.back = 0;
	if (keycode == 0)
		data->parser.map.mov.strafe_l = 0;
	if (keycode == 2)
		data->parser.map.mov.strafe_r = 0;
	if (keycode == 123)
		data->parser.map.mov.rot_l = 0;
	if (keycode == 124)
		data->parser.map.mov.rot_r = 0;
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
	if (keycode == 13)
		data->parser.map.mov.fwd = 1;
	if (keycode == 1)
		data->parser.map.mov.back = 1;
	if (keycode == 0)
		data->parser.map.mov.strafe_l = 1;
	if (keycode == 2)
		data->parser.map.mov.strafe_r = 1;
	if (keycode == 123)
		data->parser.map.mov.rot_l = 1;
	if (keycode == 124)
		data->parser.map.mov.rot_r = 1;
	return (0);
}
