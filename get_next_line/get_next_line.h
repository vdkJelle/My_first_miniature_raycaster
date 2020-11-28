/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 16:30:57 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/08 17:38:18 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

int		get_next_line(int fd, char **line);
char	*ft_strjoin_gnl(char *s1, char const *s2);
int		ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(char *s1, char offset);
int		ft_writeline_gnl(char **ret, char **line, int i);
void	*ft_memmove_gnl(void *dst, const void *src);

#endif
