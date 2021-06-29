/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 13:08:33 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/29 11:59:02 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_sprite *sprite, int num)
{
	int		i;
	int		j;
	t_pos	tmp;

	i = 0;
	while (i < num)
	{
		j = i + 1;
		while (j < num)
		{
			if (sprite->loc[i].dist < sprite->loc[j].dist)
			{
				tmp = sprite->loc[i];
				sprite->loc[i] = sprite->loc[j];
				sprite->loc[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	add_sprite(t_sprite *sprite, int map_x, int map_y, t_mov *mov)
{
	int	i;

	i = 0;
	while (i < sprite->vis)
	{
		if (sprite->loc[i].x == map_x && sprite->loc[i].y == map_y)
			return ;
		i++;
	}
	sprite->vis++;
	sprite->loc[i].x = map_x;
	sprite->loc[i].y = map_y;
	sprite->loc[i].dist = ((mov->posx - sprite->loc[i].x)
			* (mov->posx - sprite->loc[i].x) + (mov->posy - sprite->loc[i].y)
			* (mov->posy - sprite->loc[i].y));
}

void	init_sprite(t_sprite *sprite, t_parser parser)
{
	sprite->zbuf = ft_calloc(sizeof(double), parser.res_width);
	sprite->loc = ft_calloc(sizeof(t_pos), sprite->num);
	return ;
}
