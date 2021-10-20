/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 14:09:30 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/20 13:30:34 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./get_next_line/get_next_line.h"
# include "./libft/includes/libft.h"
# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define MOVSPD 0.03
# define ROTSPD 0.03

typedef struct s_ints
{
	int	x;
	int	y;
}					t_ints;

typedef struct s_doubles
{
	double	x;
	double	y;
}					t_doubles;

typedef struct s_bmp
{
	int				padding;
	int				xppm;
	int				yppm;
	unsigned int	bpp;
	unsigned int	compression;
	unsigned int	file_size;
	unsigned int	header_size;
	unsigned int	image_size;
	unsigned int	important_colours;
	unsigned int	offset;
	unsigned int	planes;
	unsigned int	reserved;
	unsigned int	total_colours;
}					t_bmp;

typedef struct s_draw_sprite
{
	int				i;
	int				x;
	int				y;
	int				d;
	int				spritescreen_x;
	int				height;
	int				width;
	int				start_y;
	int				end_y;
	int				start_x;
	int				end_x;
	int				row;
	int				col;
	unsigned int	colour;
	double			sprite_x;
	double			sprite_y;
	double			inv;
	double			transform_x;
	double			transform_y;
}					t_draw_sprite;

typedef struct s_pos
{
	int		x;
	int		y;
	double	dist;
}					t_pos;

typedef struct s_sprite
{
	t_pos	*loc;
	int		num;
	int		vis;
	double	*zbuf;
}					t_sprite;

typedef struct s_ray
{
	t_ints		map;
	t_ints		step;
	t_doubles	sidedist;
	t_doubles	deltadist;
	double		perpwalldist;
	int			hit;
}					t_ray;

typedef struct s_mov
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			side;
	int			x;
	int			fwd;
	int			back;
	int			strafe_l;
	int			strafe_r;
	int			rot_l;
	int			rot_r;
	t_sprite	sprite;
}					t_mov;

typedef struct s_map
{
	int		players;
	int		begin;
	int		end;
	int		width;
	int		height;
	char	**array;
	char	**map;
	char	*tmp;
	t_ints	pos;
	t_mov	mov;
}					t_map;

typedef struct s_error
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

typedef struct s_parser
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

typedef struct s_draw
{
	int		height;
	int		start;
	int		end;
	int		row;
	int		col;
	int		colour;
	int		tx;
	int		i;
	double	step;
	double	double_col;
}					t_draw;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
	int			height;
	int			width;
}					t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
	t_parser	parser;
	t_texture	texture[5];
}					t_data;

/*
**-----------------------------------PARSER.C-----------------------------------
*/
int				parser(t_parser *parser, char *file);

/*
**------------------------------INITIALIZE_VALUES.c-----------------------------
*/
void			set_textures(t_data *data, t_texture text[5]);
void			initialize_parser(t_parser *parser);

/*
**--------------------------------PARSER_UTILS.C--------------------------------
*/
int				fill_parser(char *line, t_parser *parser, int i);

/*
**-------------------------------ERROR_HANDLING.C-------------------------------
*/
void			check_encounters(char *line, int i, t_parser *parser);
int				check_validity(t_parser *parser);
int				print_error(char *str);

/*
**-------------------------------MAP_HANDLING.C---------------------------------
*/
void			strjoin_map(char *line, t_parser *parser);
void			make_array_map(t_map *map);

/*
**---------------------------------FLOODFILL.C----------------------------------
*/
void			check_map(t_map *map);

/*
**------------------------------FLOODFILL_UTILS.C-------------------------------
*/
int				map_error_check(t_map *map, int x, int y);
int				is_closed(t_map *map);
int				is_done(char **map, int y, int x, int height);
void			convert_x(char **map, int y, int x, int height);

/*
**--------------------------------MLX_FUNCTIONS.C-------------------------------
*/
unsigned int	bmp_get_pixel(t_data img, int x, int y);
unsigned int	my_mlx_get_pixel(t_texture img, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int u, int color);

/*
**----------------------------------MLX_HOOKS.C---------------------------------
*/
int				cross(void);
int				key_release(int keycode, t_data *data);
int				key_press(int keycode, t_data *data);

/*
**----------------------------------COLOURS.C-----------------------------------
*/
void			get_colour(t_parser *parser);

/*
**---------------------------------MAP_UTILS.C----------------------------------
*/
char			**ft_split_calloc(char const *s, int width, int wc);

/*
**---------------------------------RAYCASTING.C---------------------------------
*/
void			omg_raycasting(t_data *data, t_mov *mov);

/*
**------------------------------RAYCASTING_INFO.C-------------------------------
*/
void			find_intersect(t_ray *ray, t_mov *mov, char **map);
void			initialize_values(t_ray *ray, t_mov *mov, int res_width);
void			get_draw_info(t_draw *draw, double perpwalldist,
					t_texture texture[4], t_mov mov);

/*
**----------------------------------MOVEMENT.C----------------------------------
*/
int				detect_movement(t_data *data);

/*
**-------------------------------SPRITES_UTILS.C--------------------------------
*/
void			init_sprite(t_sprite *sprite, t_parser parser);
void			add_sprite(t_sprite *sprite, int map_x, int map_y, t_mov *mov);
void			sort_sprites(t_sprite *sprite, int num);

/*
**-------------------------------SPRITES_DRAW.C---------------------------------
*/
void			omg_spritescasting(t_data *data, t_mov *mov);

/*
**-----------------------------------BMP.C--------------------------------------
*/
void			make_bmp(char *file);

#endif
