/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/01 12:27:52 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/11/28 16:23:22 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	map_error_check(t_map *map, int x, int y)
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

static	int	is_closed(t_map *map)
{
	int x;
	int y;

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

static	int	is_done(char **map, int y, int x, int height)
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

static void	convert_x(char **map, int y, int x, int height)
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

static int	floodfill(t_map *map)
{
	int x;
	int y;
	int	count;

	count = 0;
	x = 0;
	while (map->array[x])
	{
		y = 0;
		while (map->array[x][y])
		{
			convert_x(map->array, y, x, map->height);
			y++;
		}
		x++;
	}
	x = 0;
	while (map->array[x])
	{
		y = 0;
		while (map->array[x][y])
		{
			count += is_done(map->array, y, x, map->height);
			y++;
		}
		x++;
	}
	x = 0;
	ft_printf("--------------\n");
	while (map->array[x])
	{
		ft_printf("%s\n", map->array[x]);
		x++;
	}
	return (count);
}

int			check_map(t_map *map)
{
	int	players;
	int x;
	int y;

	players = 0;
	y = 0;
	while (map->array[y])
	{
		x = 0;
		while (map->array[y][x])
		{
			if (ft_strchr("NSWE", map->array[y][x]))
			{
				players++;
				map->mov.posx = x + .5;
				map->mov.posy = y + .5;
				if (map->array[y][x] == 'N')
				{
					map->mov.dirx = -1;
					map->mov.diry = 0;
					map->mov.plane_y = 0.66;
				}
				map->array[y][x] = 'x';
			}
			x++;
		}
		y++;
	}
	if (players != 1)
		return (-1);
	while (floodfill(map))
		floodfill(map);
	if (is_closed(map) < 0)
		return (-1);
	return (0);
}

	// x = 0;
	// while (map->array[x])
	// {
	// 	ft_printf("%s\n", map->array[x]);
	// 	x++;
	// }
