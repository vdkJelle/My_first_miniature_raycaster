/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 15:38:16 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/27 17:46:00 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parser(t_parser *parser, char *file)
{
	int			ret;
	int			fd;
	char		*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Invalid file");
	initialize_parser(parser);
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (!line || ret < 0)
			print_error("Get next line failed");
		fill_parser(line, parser, 0);
		free(line);
		line = NULL;
	}
	close(fd);
	make_array_map(&parser->map);
	if (parser->map.end != 1)
		return (print_error("Please provide a valid cub file"));
	if (check_validity(parser) < 0)
		print_error(".cub file invalid");
	return (0);
}
