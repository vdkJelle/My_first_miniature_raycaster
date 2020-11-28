/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:55:53 by jelvan-d          #+#    #+#             */
/*   Updated: 2020/02/01 19:56:40 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_writeline(char **ret, char **line, int i)
{
	*line = ft_strdup(*ret, '\n');
	if (*line == NULL)
		return (-1);
	*ret = ft_memmove(*ret, (ft_strchr(*ret, '\n') + 1));
	if (**ret == 0 && i == 0)
	{
		free(*ret);
		*ret = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char			*ret[OPEN_MAX];
	char				buf[BUFFER_SIZE + 1];
	int					i;

	i = 1;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!ret[fd])
	{
		ret[fd] = malloc(sizeof(char));
		if (!ret[fd])
			return (-1);
		ret[fd][0] = '\0';
	}
	while (i && !ft_strchr(ret[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (-1);
		buf[i] = '\0';
		ret[fd] = ft_strjoin(ret[fd], buf);
		if (ret[fd] == 0)
			return (-1);
	}
	return (ft_writeline(&ret[fd], line, i));
}
