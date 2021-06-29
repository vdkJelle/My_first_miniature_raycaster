/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 15:09:45 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/01/27 13:04:53 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cleanup(char **p, int pi)
{
	int	i;

	i = 0;
	while (i < pi)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static char	**write_calloc(char const *s, char **p, int wc, int width)
{
	int		m;
	int		i;

	i = 0;
	m = 0;
	while (wc > 0)
	{
		p[0] = (char *)ft_calloc(sizeof(char) * (width + 1), 1);
		if (p[0] == 0)
			return (0);
		while (s[i] == '\n')
			i++;
		while (s[i] != '\n' && s[i] != '\0')
		{
			p[0][m] = s[i];
			i++;
			m++;
		}
		m = 0;
		p++;
		wc--;
	}
	return (0);
}

char	**ft_split_calloc(char const *s, int width, int wc)
{
	char	**p;
	int		pi;

	if (s == 0)
		return (0);
	pi = 0;
	p = (char **)malloc(sizeof(char *) * (wc + 1));
	if (p == 0)
		return (0);
	write_calloc(s, p, wc, width);
	while (pi < wc)
	{
		if (p[pi] == NULL)
		{
			cleanup(p, pi);
			return (NULL);
		}
		pi++;
	}
	p[wc] = NULL;
	return (p);
}
