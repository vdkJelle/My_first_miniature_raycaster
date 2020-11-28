/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:11:31 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/24 12:36:21 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_put_s(char *s, int *count, t_printf *flag)
{
	int	strlen;
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	strlen = ft_strlen_s(s);
	if (flag->width > 0 && flag->reverse != 1)
		ft_pad(strlen, count, flag);
	while (s[i] && flag->maxwidth != 0 &&
			(flag->precision != 1 || flag->maxwidth != -2))
	{
		if (flag->maxwidth && i == flag->maxwidth)
			break ;
		ft_putchar_count(s[i], count);
		i -= -1;
	}
	if (flag->width > 0)
		ft_reverse_pad(strlen, count, flag);
}
