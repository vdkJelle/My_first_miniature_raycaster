/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 15:38:16 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/29 17:14:40 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

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
		if (!line)
			return (-1);
		fill_parser(line, parser, 0);
		free(line);
		line = NULL;
	}
	close(fd);
	if (parser->map.end != 1)
		return (print_error("Please provide a valid cub file"));
	if (check_validity(parser) < 0)
		return (-1);
	return (0);
}
