/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 12:01:56 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/27 13:01:12 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			return ;
		parser->map.tmp[0] = '\0';
	}
	parser->map.begin = 1;
	parser->map.tmp = ft_strjoin_cub3d(parser->map.tmp, line);
	if (!parser->map.tmp)
		return ;
	parser->map.height++;
}

void	make_array_map(t_map *map)
{
	map->begin = -1;
	map->end = 1;
	map->array = ft_split_calloc(map->tmp, map->width, map->height);
	map->map = ft_split_calloc(map->tmp, map->width, map->height);
	if (!map->array)
		return ;
}
