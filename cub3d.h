/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 14:09:30 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/11/28 16:56:56 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./get_next_line/get_next_line.h"
# include "./libft/includes/libft.h"
# include "./ft_printf/printf.h"
# include "./minilibx_mac/mlx.h"
# include <stdlib.h>
# include <math.h>

typedef struct		s_mov
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
}					t_mov;

typedef struct		s_map
{
	int		begin;
	int		end;
	int		width;
	int		height;
	char	**array;
	char	**map;
	char	*tmp;
	t_mov	mov;
}					t_map;

typedef struct		s_error
{
	int		seen_r;
	int		seen_no;
	int		seen_so;
	int		seen_we;
	int		seen_ea;
	int		seen_s;
	int		seen_c;
	int		seen_f;
}					t_error;

typedef struct		s_parser
{
	int		res_width;
	int		res_height;
	char	no_wall[50];
	char	so_wall[50];
	char	we_wall[50];
	char	ea_wall[50];
	char	obj_sprite[50];
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	int		trgb_ceil;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		trgb_floor;
	t_error	error;
	t_map	map;
}					t_parser;

typedef struct		s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
	t_parser	parser;
}					t_data;

/*
** parser.c
*/
int					parser(t_parser *parser);

/*
**initialize_struct.c
*/
void				initialize_parser(t_parser *parser);

/*
**parser_utils.c
*/
int					fill_parser(char *line, t_parser *parser);

/*
**error_handling.c
*/
void				check_encounters(char *line, int i, t_parser *parser);
int					check_validity(t_parser *parser);
int					print_error(char *str);

/*
**map_handling.c
*/
void				strjoin_map(char *line, t_parser *parser);
void				make_array_map(t_map *map);

/*
**floodfill.c
*/
int					check_map(t_map *map);

/*
**my_mlx_pixel_put.c
*/
void				my_mlx_pixel_put(t_data *data, int x, int u, int color);

/*
**colours.c
*/
void				get_colour(t_parser *parser);

/*
**map_utils.c
*/
char				**ft_split_calloc(char const *s, int width, int wc);

/*
**raycasting.c
*/

void				omgraycasting(t_data *data, t_mov *mov);

#endif
