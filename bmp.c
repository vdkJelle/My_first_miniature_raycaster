/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 15:41:27 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/29 09:59:58 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	write_to_fd(int fd, const void *buf, int byte)
{
	int	r;

	r = write(fd, buf, byte);
	if (r == -1)
		print_error("Write failed");
}

static void	draw_bmp(t_data data, t_bmp bmp, int fd)
{
	int				x;
	int				y;
	unsigned int	colour;
	char			c;

	c = 0x00;
	x = data.parser.res_height - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < data.parser.res_width)
		{
			colour = bmp_get_pixel(data, y, x);
			write_to_fd(fd, &colour, 3);
			y++;
		}
		y = 0;
		while (y < bmp.padding)
		{
			write_to_fd(fd, &c, 1);
			y++;
		}
		x--;
	}
}

static int	create_header(t_data data, t_bmp bmp)
{
	int		fd;

	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		print_error("Failed to open file");
	write_to_fd(fd, "BM", 2);
	write_to_fd(fd, &bmp.file_size, 4);
	write_to_fd(fd, &bmp.reserved, 2);
	write_to_fd(fd, &bmp.reserved, 2);
	write_to_fd(fd, &bmp.offset, 4);
	write_to_fd(fd, &bmp.header_size, 4);
	write_to_fd(fd, &data.parser.res_width, 4);
	write_to_fd(fd, &data.parser.res_height, 4);
	write_to_fd(fd, &bmp.planes, 2);
	write_to_fd(fd, &bmp.bpp, 2);
	write_to_fd(fd, &bmp.compression, 4);
	write_to_fd(fd, &bmp.image_size, 4);
	write_to_fd(fd, &bmp.xppm, 4);
	write_to_fd(fd, &bmp.yppm, 4);
	write_to_fd(fd, &bmp.total_colours, 4);
	write_to_fd(fd, &bmp.important_colours, 4);
	return (fd);
}

static void	get_header_info(t_data data, t_bmp *bmp)
{
	bmp->bpp = 24;
	bmp->header_size = 40;
	if (((data.parser.res_width * 3) % 4) != 0)
		bmp->padding = 4 - ((data.parser.res_width * 3) % 4);
	bmp->file_size = 54 + (data.parser.res_width * data.parser.res_height * 3)
		+ (bmp->padding * data.parser.res_height);
	bmp->offset = 54;
	bmp->planes = 1;
}

void	make_bmp(char *file)
{
	t_data	data;
	t_bmp	bmp;
	int		fd;

	printf("Making screenshot\n");
	ft_bzero(&bmp, sizeof(bmp));
	parser(&data.parser, file);
	init_sprite(&data.parser.map.mov.sprite, data.parser);
	get_colour(&data.parser);
	data.mlx = mlx_init();
	data.img = mlx_new_image(data.mlx, data.parser.res_width,
			data.parser.res_height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.length,
			&data.endian);
	set_textures(&data, data.texture);
	omg_raycasting(&data, &data.parser.map.mov);
	get_header_info(data, &bmp);
	fd = create_header(data, bmp);
	draw_bmp(data, bmp, fd);
	close(fd);
	printf("Screenshot saved as screenshot.bmp\nExiting...\n");
	exit (0);
}
