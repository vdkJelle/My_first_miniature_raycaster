/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 16:15:05 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/25 11:54:19 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_colour_ceiling(char *line, t_parser *parser, int i)
{
	int	wc;

	wc = count_words(line, ',');
	if (wc != 3 || line[i] != ' ')
		return ;
	while (line[i] == ' ' && line[i])
		i++;
	parser->ceiling_r = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while ((line[i] == ' ' || (line[i] == ',' && line[i + 1] != ',')))
		i++;
	parser->ceiling_g = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while ((line[i] == ' ' || (line[i] == ',' && line[i + 1] != ',')))
		i++;
	parser->ceiling_b = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i])
		parser->ceiling_r = -1;
}

static void	get_colour_floor(char *line, t_parser *parser, int i)
{
	int	wc;

	wc = count_words(line, ',');
	if (wc != 3 || line[i] != ' ')
		return ;
	while (line[i] == ' ' && line[i])
		i++;
	parser->floor_r = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while ((line[i] == ' ' || (line[i] == ',' && line[i + 1] != ',')))
		i++;
	parser->floor_g = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while ((line[i] == ' ' || (line[i] == ',' && line[i + 1] != ',')))
		i++;
	parser->floor_b = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i])
		parser->floor_r = -1;
}

static void	get_string(char *line, int i, char *str)
{
	int	start;
	int	wc;

	wc = count_words(line, ' ');
	if (wc != 2 || line[i] != ' ')
		return ;
	while (line[i] == ' ' && line[i])
		i++;
	start = i;
	while (line[i] && line[i] != ' ')
		i++;
	str = ft_substr(str, start, i - start);
	if (!str)
		print_error("Malloc failed");
}

static void	get_resolution(char *line, t_parser *parser, int i)
{
	int	wc;

	wc = count_words(line + i, ' ');
	if (wc != 2 || line[i] != ' ')
		return ;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		parser->res_width = parser->res_width * 10 + line[i] - '0';
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		parser->res_height = parser->res_height * 10 + line[i] - '0';
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i])
		parser->res_width = -1;
}

int	fill_parser(char *line, t_parser *parser, int i)
{
	while (line[i] == ' ' && line[i])
		i++;
	check_encounters(line, i, parser);
	if (line[i] == 'R' && !parser->map.begin)
		get_resolution(line, parser, i + 1);
	else if (line[i] == 'N' && line[i + 1] == 'O' && !parser->map.begin)
		get_string(line, i + 2, parser->no_wall);
	else if (line[i] == 'S' && line[i + 1] == 'O' && !parser->map.begin)
		get_string(line, i + 2, parser->so_wall);
	else if (line[i] == 'W' && line[i + 1] == 'E' && !parser->map.begin)
		get_string(line, i + 2, parser->we_wall);
	else if (line[i] == 'E' && line[i + 1] == 'A' && !parser->map.begin)
		get_string(line, i + 2, parser->ea_wall);
	else if (line[i] == 'S' && line[i + 1] != 'O' && !parser->map.begin)
		get_string(line, i + 1, parser->obj_sprite);
	else if (line[i] == 'F' && !parser->map.begin)
		get_colour_floor(line, parser, i + 1);
	else if (line[i] == 'C' && !parser->map.begin)
		get_colour_ceiling(line, parser, i + 1);
	else if ((line[i] == '1' || line[i] == '0') && parser->map.end != 1)
		strjoin_map(line, parser);
	else if (parser->map.begin == 1 && *line == '\0')
		make_array_map(&parser->map);
	return (0);
}
