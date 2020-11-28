/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:26:39 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/23 13:46:12 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_pad(int len, int *count, t_printf *flag)
{
	if (flag->maxwidth > 0 && (flag->maxwidth <= len))
		flag->width -= (flag->maxwidth);
	else if (flag->precision != 1 || flag->maxwidth != -2)
		flag->width -= len;
	while (flag->width > 0)
	{
		if (flag->padding == 1 && flag->reverse != 1
			&& flag->maxwidth < flag->width)
			ft_putchar_count('0', count);
		else
			ft_putchar_count(' ', count);
		(flag->width)--;
	}
}
