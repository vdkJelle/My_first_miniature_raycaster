/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/01 12:27:52 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/29 16:52:13 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_done(t_map *map)
{
	int		count;

	count = 0;
	map->pos.x = 0;
	while (map->array[map->pos.x])
	{
		map->pos.y = 0;
		while (map->array[map->pos.x][map->pos.y])
		{
			count += is_done(map->array, map->pos.y, map->pos.x, map->height);
			map->pos.y++;
		}
		map->pos.x++;
	}
	return (count);
}

static int	floodfill(t_map *map)
{
	int		count;

	count = 0;
	map->pos.x = 0;
	while (map->array[map->pos.x])
	{
		map->pos.y = 0;
		while (map->array[map->pos.x][map->pos.y])
		{
			convert_x(map->array, map->pos.y, map->pos.x, map->height);
			map->pos.y++;
		}
		map->pos.x++;
	}
	map->pos.x = 0;
	count = check_done(map);
	return (count);
}

static void	starting_direction(t_map *map, int x, int y)
{
	if (map->array[x][y] == 'N')
	{
		map->mov.dirx = -1;
		map->mov.plane_y = 0.66;
	}
	else if (map->array[x][y] == 'E')
	{		
		map->mov.diry = 1;
		map->mov.plane_x = 0.66;
	}
	else if (map->array[x][y] == 'S')
	{
		map->mov.dirx = 1;
		map->mov.plane_y = -0.66;
	}
	else if (map->array[x][y] == 'W')
	{
		map->mov.diry = -1;
		map->mov.plane_x = -0.66;
	}
}

void	check_map(t_map *map)
{
	while (map->array[map->pos.x])
	{
		map->pos.y = 0;
		while (map->array[map->pos.x][map->pos.y])
		{
			if (ft_strchr("NSWE", map->array[map->pos.x][map->pos.y]))
			{
				map->players++;
				map->mov.posy = map->pos.y + .5;
				map->mov.posx = map->pos.x + .5;
				starting_direction(map, map->pos.x, map->pos.y);
				map->array[map->pos.x][map->pos.y] = 'x';
			}
			else if (map->array[map->pos.x][map->pos.y] == '2')
				map->mov.sprite.num++;
			map->pos.y++;
		}
		map->pos.x++;
	}
	if (map->players != 1)
		print_error("Incorrect amount of players on map");
	while (floodfill(map))
		floodfill(map);
	if (is_closed(map) < 0)
		print_error("Map is not closed");
}
