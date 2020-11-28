/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 11:43:09 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/22 16:28:06 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

/*
**  to fix:
**	-- Free 2d array and strjoin if error
*/

int	close_window(int keycode, t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	return (0);
}

int	main(void)
{
	t_data	img;

	parser(&img.parser);
	get_colour(&img.parser);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.parser.res_width, img.parser.res_height, "Cub3d");
	img.img = mlx_new_image(img.mlx, img.parser.res_width, img.parser.res_height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.length, &img.endian);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, close_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
