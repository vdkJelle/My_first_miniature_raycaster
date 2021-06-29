/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:21:16 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/26 12:24:46 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_error_check(t_map *map, int x, int y)
{
	if (!map->array[x - 1][y - 1])
		return (-1);
	if (!map->array[x - 1][y])
		return (-1);
	if (!map->array[x - 1][y + 1])
		return (-1);
	if (!map->array[x][y - 1])
		return (-1);
	if (!map->array[x][y + 1])
		return (-1);
	if (!map->array[x + 1][y - 1])
		return (-1);
	if (!map->array[x + 1][y])
		return (-1);
	if (!map->array[x + 1][y + 1])
		return (-1);
	return (0);
}

int	is_closed(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->array[x])
	{
		y = 0;
		if (map->array[x][y] == 'x')
			return (-1);
		while (map->array[x][y])
		{
			if (map->array[x][y] == 'x' && (x == 0 || x == map->height - 1))
				return (-1);
			if (map->array[x][y] == 'x' || ft_strchr("NWSE", map->array[x][y]))
				if (map_error_check(map, x, y) == -1)
					return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

int	is_done(char **map, int y, int x, int height)
{
	int	changed;

	changed = 0;
	if (map[x][y] == 'x' && x != 0 && x != (height - 1) && y > 0)
	{
		if (ft_strchr("02 ", map[x - 1][y - 1]) && map[x - 1][y - 1])
			changed++;
		if (ft_strchr("02 ", map[x - 1][y]) && map[x - 1][y])
			changed++;
		if (ft_strchr("02 ", map[x - 1][y + 1]) && map[x - 1][y + 1])
			changed++;
		if (ft_strchr("02 ", map[x][y - 1]) && map[x][y - 1])
			changed++;
		if (ft_strchr("02 ", map[x][y + 1]) && map[x][y + 1])
			changed++;
		if (ft_strchr("02 ", map[x + 1][y - 1]) && map[x + 1][y - 1])
			changed++;
		if (ft_strchr("02 ", map[x + 1][y]) && map[x + 1][y])
			changed++;
		if (ft_strchr("02 ", map[x + 1][y + 1]) && map[x + 1][y + 1])
			changed++;
	}
	return (changed);
}

void	convert_x(char **map, int y, int x, int height)
{
	if (map[x][y] == 'x' && x != 0 && x != (height - 1) && y > 0)
	{
		if (ft_strchr("02 ", map[x - 1][y - 1]) && map[x - 1][y - 1])
			map[x - 1][y - 1] = 'x';
		if (ft_strchr("02 ", map[x - 1][y]) && map[x - 1][y])
			map[x - 1][y] = 'x';
		if (ft_strchr("02 ", map[x - 1][y + 1]) && map[x - 1][y + 1])
			map[x - 1][y + 1] = 'x';
		if (ft_strchr("02 ", map[x][y - 1]) && map[x][y - 1])
			map[x][y - 1] = 'x';
		if (ft_strchr("02 ", map[x][y + 1]) && map[x][y + 1])
			map[x][y + 1] = 'x';
		if (ft_strchr("02 ", map[x + 1][y - 1]) && map[x + 1][y - 1])
			map[x + 1][y - 1] = 'x';
		if (ft_strchr("02 ", map[x + 1][y]) && map[x + 1][y])
			map[x + 1][y] = 'x';
		if (ft_strchr("02 ", map[x + 1][y + 1]) && map[x + 1][y + 1])
			map[x + 1][y + 1] = 'x';
	}
}
