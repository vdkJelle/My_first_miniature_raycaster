/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 12:01:56 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/11/28 15:35:28 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
	map->array = NULL;
}

static char	*ft_strjoin_cub3d(char *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2));
	if (!p)
	{
		free(s1);
		return (0);
	}
	while (s1[i])
	{
		p[i] = s1[i];
		i -= -1;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j -= -1;
	}
	free(s1);
	p[i + j] = '\n';
	p[i + j + 1] = '\0';
	return (p);
}

void		strjoin_map(char *line, t_parser *parser)
{
	if (ft_strlen(line) > parser->map.width)
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

void		make_array_map(t_map *map)
{
	map->end = 1;
	map->array = ft_split_calloc(map->tmp, map->width, map->height);
	if (!map->array)
		return ;
	// map_free(map);
}
