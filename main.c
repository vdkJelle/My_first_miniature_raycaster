/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 11:43:09 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/27 14:35:39 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_resolution(int *height, int *width)
{
	if (*height > 1440)
		*height = 1440;
	if (*width > 2560)
		*width = 2560;
}

static int	check_extension(char *file, char *set)
{
	int	i;

	i = ft_strlen(file) - 1;
	while (file[i] == ' ')
		i--;
	if (file[i] == set[3] && file[i - 1] == set[2]
		&& file[i - 2] == set[1] && file[i - 3] == set[0])
		return (0);
	return (1);
}

static void	cub3d(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error("Mlx initalisation failed");
	set_textures(data, data->texture);
	data->mlx_win = mlx_new_window(data->mlx, data->parser.res_width,
			data->parser.res_height, "Cub3d");
	if (!data->mlx_win)
		print_error("Mlx window creation failed");
	data->img = mlx_new_image(data->mlx, data->parser.res_width,
			data->parser.res_height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->length,
			&data->endian);
	mlx_do_sync(data->mlx);
	omg_raycasting(data, &data->parser.map.mov);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_win, 17, 0L, cross, data);
	mlx_loop_hook(data->mlx, &detect_movement, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && argc != 3)
		print_error("Please provide valid arguments");
	if (ft_strlen(argv[1]) < 4 || check_extension(argv[1], ".cub"))
		print_error("Please provide a .cub file");
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6)
		&& ft_strlen(argv[2]) == 6)
		make_bmp(argv[1]);
	else if (argc == 3)
		print_error("Invalid arguments provided");
	parser(&data.parser, argv[1]);
	check_resolution(&data.parser.res_height, &data.parser.res_width);
	init_sprite(&data.parser.map.mov.sprite, data.parser);
	get_colour(&data.parser);
	cub3d(&data);
	exit(0);
	return (0);
}
