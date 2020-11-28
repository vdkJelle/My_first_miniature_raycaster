/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:33:27 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/11/29 11:51:27 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
