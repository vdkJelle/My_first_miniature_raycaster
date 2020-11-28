/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 15:38:16 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/22 14:32:34 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

int			parser(t_parser *parser)
{
	int			ret;
	int			fd;
	char		*line;

	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		return (-1);
	initialize_parser(parser);
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (!line)
			return (-1);
		fill_parser(line, parser);
		free(line);
		line = NULL;
	}
	close(fd);
	if (parser->map.end != 1)
		return (print_error("Please provide a valid cub file"));
	// ft_printf("width:%d\nheight:%d\nno_wall sprite:%s\nso_wall sprite:%s\nwe_wall sprite:%s\nea_wall sprite:%s\nobj_sprite:%s\nfloor_r:%d\nfloor_g:%d\nfloor_b:%d\nceiling_r:%d\nceiling_g:%d\nceiling_b:%d\n", parser->res_width, parser->res_height, parser->no_wall, parser->so_wall, parser->we_wall, parser->ea_wall, parser->obj_sprite, parser->floor_r, parser->floor_g, parser->floor_b, parser->ceiling_r, parser->ceiling_g, parser->ceiling_b);
	//ft_printf("seen_r:%d\nseen_no:%d\nseen_so:%d\nseen_we:%d\nseen_ea:%d\nseen_s:%d\nseen_c:%d\nseen_f:%d\n", parser->error.seen_r, parser->error.seen_no,parser->error.seen_so,parser->error.seen_we,parser->error.seen_ea,parser->error.seen_s,parser->error.seen_c,parser->error.seen_f);
	if (check_validity(parser) < 0)
		return (-1);
	return (0);
}
