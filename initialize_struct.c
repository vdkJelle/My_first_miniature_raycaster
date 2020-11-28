/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_struct.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 11:08:21 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/11/28 13:15:00 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_map(t_map *map)
{
	map->begin = 0;
	map->end = 0;
	map->height = 0;
	map->width = 0;
	map->mov.plane_x = 0;
	map->mov.plane_y = 0.66;
	map->mov.time = 0;
	map->mov.old_time = 0;
}

static void	initialize_error(t_error *error)
{
	error->seen_r = 0;
	error->seen_no = 0;
	error->seen_so = 0;
	error->seen_we = 0;
	error->seen_ea = 0;
	error->seen_s = 0;
	error->seen_c = 0;
	error->seen_f = 0;
}

void		initialize_parser(t_parser *parser)
{
	initialize_error(&parser->error);
	initialize_map(&parser->map);
	parser->res_width = 0;
	parser->res_height = 0;
	parser->no_wall[0] = '\0';
	parser->so_wall[0] = '\0';
	parser->we_wall[0] = '\0';
	parser->ea_wall[0] = '\0';
	parser->obj_sprite[0] = '\0';
	parser->ceiling_r = -1;
	parser->ceiling_g = -1;
	parser->ceiling_b = -1;
	parser->floor_r = -1;
	parser->floor_g = -1;
	parser->floor_b = -1;
}
