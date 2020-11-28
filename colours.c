/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colours.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 11:26:15 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/22 14:26:56 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void			get_colour(t_parser *parser)
{
	parser->trgb_floor = create_trgb(0, parser->floor_r, parser->floor_g,
										parser->floor_b);
	parser->trgb_ceil = create_trgb(0, parser->ceiling_r, parser->ceiling_g,
										parser->ceiling_b);
}
