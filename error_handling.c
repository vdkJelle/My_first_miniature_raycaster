/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 12:42:15 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/27 16:08:31 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_seen_after_map(char *line, int i, t_parser *parser)
{
	if (line[i] == 'R')
		parser->error.seen_r = 2;
	else if (line[i] == 'N' && line[i + 1] == 'O')
		parser->error.seen_no = 2;
	else if (line[i] == 'S' && line[i + 1] == 'O')
		parser->error.seen_so = 2;
	else if (line[i] == 'W' && line[i + 1] == 'E')
		parser->error.seen_we = 2;
	else if (line[i] == 'E' && line[i + 1] == 'A')
		parser->error.seen_ea = 2;
	else if (line[i] == 'S' && line[i + 1] != 'O')
		parser->error.seen_so = 2;
	else if (line[i] == 'F')
		parser->error.seen_f = 2;
	else if (line[i] == 'C')
		parser->error.seen_c = 2;
}

void	check_encounters(char *line, int i, t_parser *parser)
{
	if (parser->map.begin != 1)
	{
		if (line[i] == 'R')
			parser->error.seen_r++;
		else if (line[i] == 'N' && line[i + 1] == 'O')
			parser->error.seen_no++;
		else if (line[i] == 'S' && line[i + 1] == 'O')
			parser->error.seen_so++;
		else if (line[i] == 'W' && line[i + 1] == 'E')
			parser->error.seen_we++;
		else if (line[i] == 'E' && line[i + 1] == 'A')
			parser->error.seen_ea++;
		else if (line[i] == 'S' && line[i + 1] != 'O')
			parser->error.seen_s++;
		else if (line[i] == 'F')
			parser->error.seen_f++;
		else if (line[i] == 'C')
			parser->error.seen_c++;
	}
	else
		check_seen_after_map(line, i, parser);
}

int	check_validity(t_parser *parser)
{
	if (parser->res_width < 1 || parser->res_height < 1)
		return (print_error("Please enter a valid resolution"));
	if (!parser->no_wall || !parser->so_wall || !parser->ea_wall
		|| !parser->we_wall || !parser->obj_sprite)
		return (print_error("Please enter valid textures"));
	if (parser->ceiling_r < 0 || parser->ceiling_r > 255
		|| parser->ceiling_g < 0 || parser->ceiling_g > 255
		|| parser->ceiling_b < 0 || parser->ceiling_b > 255)
		return (print_error("Please enter a valid ceiling colour range"));
	if (parser->floor_r < 0 || parser->floor_r > 255 || parser->floor_g < 0
		|| parser->floor_g > 255 || parser->floor_b < 0
		|| parser->floor_b > 255)
		return (print_error("Please enter a valid floor colour range"));
	if (parser->error.seen_r > 1 || parser->error.seen_no > 1
		|| parser->error.seen_so > 1 || parser->error.seen_we > 1
		|| parser->error.seen_ea > 1 || parser->error.seen_s > 1
		|| parser->error.seen_c > 1 || parser->error.seen_f > 1)
		return (print_error("Duplicate identifier spotted"));
	check_map(&parser->map);
	return (0);
}

int	print_error(char *str)
{
	printf("Error\n%s. You fucking lobster.\n", str);
	exit (1);
}
