/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:37:48 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/04/09 15:34:30 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*p;

	if (s == 0)
		return (0);
	i = 0;
	p = malloc(ft_strlen(s) + 1);
	if (p == 0)
		return (0);
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i -= -1;
	}
	p[i] = '\0';
	return (p);
}
