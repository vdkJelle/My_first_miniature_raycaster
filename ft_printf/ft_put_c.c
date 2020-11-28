/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:28:36 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/18 09:28:48 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_put_c(int c, int *count, t_printf *flag)
{
	if (flag->width > 0 && flag->reverse != 1)
		ft_pad(1, count, flag);
	ft_putchar_count((char)c, count);
	if (flag->width > 0)
		ft_reverse_pad(1, count, flag);
}
