/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 07:28:48 by jelvan-d          #+#    #+#             */
/*   Updated: 2020/02/01 19:56:35 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, const void *src)
{
	int	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (((char *)dst) < ((char *)src))
	{
		while (((char *)src)[i])
		{
			((char *)dst)[i] = ((char *)src)[i];
			i -= -1;
		}
	}
	((char *)dst)[i] = '\0';
	return (dst);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i -= -1;
	return (i);
}

char	*ft_strdup(char *s1, char offset)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (p == 0)
		return (NULL);
	while (s1[i] && s1[i] != offset)
	{
		p[i] = s1[i];
		i -= -1;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i -= -1;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == 0)
	{
		free(s1);
		return (0);
	}
	while (s1[i])
	{
		p[i] = s1[i];
		i -= -1;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j -= -1;
	}
	free(s1);
	p[i + j] = '\0';
	return (p);
}
