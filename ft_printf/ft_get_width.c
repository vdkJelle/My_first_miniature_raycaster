/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:24:02 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/27 16:00:20 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_width(const char ***input, va_list arg, t_printf *flag)
{
	int	res;

	res = 0;
	if (***input == '-')
		**input -= -1;
	if (***input >= '0' && ***input <= '9')
	{
		while (***input >= '0' && ***input <= '9')
		{
			res = res * 10 + (***input - '0');
			**input -= -1;
		}
		**input -= 1;
	}
	else if (***input == '*')
		res = va_arg(arg, int);
	if (res < 0 && flag->precision != 1)
	{
		res *= -1;
		flag->reverse = 1;
	}
	else if (res < 0 && flag->precision == 1)
		res = 0;
	return (res);
}
