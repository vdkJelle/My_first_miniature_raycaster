/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 11:43:09 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/11/28 17:00:44 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

/*
**  to fix:
**	-- Free 2d array and strjoin if error
*/

int	close_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

int	main(void)
{
	t_data	data;

	parser(&data.parser);
	get_colour(&data.parser);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.parser.res_width, data.parser.res_height, "Cub3d");
	data.img = mlx_new_image(data.mlx, data.parser.res_width, data.parser.res_height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.length, &data.endian);
	omgraycasting(&data, &data.parser.map.mov);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
