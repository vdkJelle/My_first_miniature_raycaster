/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 11:01:58 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/27 13:06:00 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	bmp_get_pixel(t_data img, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = img.addr + (y * img.length + x * (img.bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

unsigned int	my_mlx_get_pixel(t_texture img, int y, int x)
{
	char			*dst;
	unsigned int	color;

	if (x >= img.height || x < 0 || y >= img.width || y < 0)
		return (0xFF000000);
	dst = img.addr + (x * img.length + y * (img.bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if ((color & 0x00FFFFFF) == 0)
		return ;
	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
