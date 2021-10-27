/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_values.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 11:08:21 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/27 12:02:02 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_texture_img(t_texture *text)
{
	if (!text[0].img)
		print_error("Failed to load north wall texture");
	if (!text[1].img)
		print_error("Failed to load east wall texture");
	if (!text[2].img)
		print_error("Failed to load south wall texture");
	if (!text[3].img)
		print_error("Failed to load west wall texture");
	if (!text[4].img)
		print_error("Failed to load sprite texture");
}

static void	check_texture_addr(t_texture *text)
{
	if (!text[0].addr)
		print_error("Failed to load north wall texture");
	if (!text[1].addr)
		print_error("Failed to load east wall texture");
	if (!text[2].addr)
		print_error("Failed to load south wall texture");
	if (!text[3].addr)
		print_error("Failed to load west wall texture");
	if (!text[4].addr)
		print_error("Failed to load sprite texture");
}

void	set_textures(t_data *data, t_texture *text)
{
	text[0].img = mlx_xpm_file_to_image(data->mlx, data->parser.no_wall,
			&text[0].width, &text[0].height);
	text[1].img = mlx_xpm_file_to_image(data->mlx, data->parser.ea_wall,
			&text[1].width, &text[1].height);
	text[2].img = mlx_xpm_file_to_image(data->mlx, data->parser.so_wall,
			&text[2].width, &text[2].height);
	text[3].img = mlx_xpm_file_to_image(data->mlx, data->parser.we_wall,
			&text[3].width, &text[3].height);
	text[4].img = mlx_xpm_file_to_image(data->mlx,
			data->parser.obj_sprite, &text[4].width, &text[4].height);
	check_texture_img(text);
	text[0].addr = mlx_get_data_addr(text[0].img,
			&text[0].bpp, &text[0].length, &text[0].endian);
	text[1].addr = mlx_get_data_addr(text[1].img,
			&text[1].bpp, &text[1].length, &text[1].endian);
	text[2].addr = mlx_get_data_addr(text[2].img, &text[2].bpp,
			&text[2].length, &text[2].endian);
	text[3].addr = mlx_get_data_addr(text[3].img,
			&text[3].bpp, &text[3].length, &text[3].endian);
	text[4].addr = mlx_get_data_addr(text[4].img,
			&text[4].bpp, &text[4].length, &text[4].endian);
	check_texture_addr(text);
}

void	initialize_parser(t_parser *parser)
{
	ft_bzero(&parser->error, sizeof(parser->error));
	ft_bzero(&parser->map, sizeof(parser->map));
	parser->res_width = 0;
	parser->res_height = 0;
	parser->no_wall = NULL;
	parser->so_wall = NULL;
	parser->we_wall = NULL;
	parser->ea_wall = NULL;
	parser->obj_sprite = NULL;
	parser->ceiling_r = -1;
	parser->ceiling_g = -1;
	parser->ceiling_b = -1;
	parser->floor_r = -1;
	parser->floor_g = -1;
	parser->floor_b = -1;
}
