/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 12:01:56 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/25 12:13:07 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_for_invalid_characters(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != '2' && map[i] != 'N'
			&& map[i] != 'E' && map[i] != 'S' && map[i] != 'W' && map[i] != ' '
			&& map[i] != '\n')
			print_error("Invalid character in map");
		i++;
	}
}

static char	*ft_strjoin_cub3d(char *s1, char const *s2)
{
	char	*p;
	t_ints	idx;

	idx.x = 0;
	idx.y = 0;
	p = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2));
	if (!p)
	{
		free(s1);
		return (0);
	}
	while (s1[idx.x])
	{
		p[idx.x] = s1[idx.x];
		idx.x -= -1;
	}
	while (s2[idx.y])
	{
		p[idx.x + idx.y] = s2[idx.y];
		idx.y -= -1;
	}
	free(s1);
	p[idx.x + idx.y] = '\n';
	p[idx.x + idx.y + 1] = '\0';
	return (p);
}

void	strjoin_map(char *line, t_parser *parser)
{
	if (ft_strlen(line) > (size_t)parser->map.width)
		parser->map.width = ft_strlen(line);
	if (!parser->map.begin)
	{
		parser->map.tmp = malloc(sizeof(char));
		if (!parser->map.tmp)
			print_error("Malloc failed");
		parser->map.tmp[0] = '\0';
	}
	parser->map.begin = 1;
	parser->map.tmp = ft_strjoin_cub3d(parser->map.tmp, line);
	if (!parser->map.tmp)
		print_error("Malloc failed");
	parser->map.height++;
}

void	make_array_map(t_map *map)
{
	map->begin = -1;
	map->end = 1;
	check_for_invalid_characters(map->tmp);
	map->array = ft_split_calloc(map->tmp, map->width, map->height);
	if (!map->array)
		print_error("Malloc failed");
	map->map = ft_split_calloc(map->tmp, map->width, map->height);
	if (!map->array)
		print_error("Malloc failed");
}
