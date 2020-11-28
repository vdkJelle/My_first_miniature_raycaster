/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_pad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:45:04 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/23 13:41:36 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_reverse_pad(int len, int *count, t_printf *flag)
{
	if (flag->maxwidth > 0 && flag->maxwidth <= len)
		flag->width -= (flag->maxwidth);
	else if (flag->precision != 1 || flag->maxwidth != -2)
		flag->width -= len;
	while (flag->width > 0)
	{
		ft_putchar_count(' ', count);
		(flag->width)--;
	}
}
