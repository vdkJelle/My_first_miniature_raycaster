/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:11:53 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/27 16:46:08 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	flag_reset(t_printf *flag)
{
	flag->maxwidth = -2;
	flag->reverse = 0;
	flag->width = 0;
	flag->padding = 0;
	flag->precision = 0;
	flag->sign = 0;
}

static void	flag_compare(const char **input, va_list arg,
									t_printf *flag)
{
	while (**input != 'c' && **input != 's' && **input != 'p' &&
			**input != 'd' && **input != 'i' && **input != 'u' &&
			**input != 'x' && **input != 'X' && **input != '%')
	{
		if (**input == '-')
			flag->reverse = 1;
		if (**input == '0')
			flag->padding = 1;
		if (((**input >= '0' && **input <= '9') || **input == '*')
			&& flag->precision == 1)
			flag->maxwidth = ft_get_width(&input, arg, flag);
		if (((**input >= '0' && **input <= '9') || **input == '*')
			&& flag->precision != 1)
			flag->width = ft_get_width(&input, arg, flag);
		if (**input == '.')
			flag->precision = 1;
		if (flag->padding == 1 && flag->reverse == 1)
			flag->padding = 0;
		*input -= -1;
	}
}

static void	conv_compare(const char *input, va_list arg,
						int *count, t_printf *flag)
{
	if (*input == 'c')
		ft_put_c(va_arg(arg, int), count, flag);
	if (*input == 's')
		ft_put_s(va_arg(arg, char *), count, flag);
	if (*input == 'p')
		ft_put_p((unsigned long)va_arg(arg, void *), count, flag);
	if (*input == 'd')
		ft_putnbr(va_arg(arg, int), count, flag);
	if (*input == 'i')
		ft_putnbr(va_arg(arg, int), count, flag);
	if (*input == 'u')
		ft_put_u(va_arg(arg, unsigned int), count, flag);
	if (*input == 'x')
		ft_putnbr_hex_low(va_arg(arg, unsigned int), count, flag);
	if (*input == 'X')
		ft_putnbr_hex_up(va_arg(arg, unsigned int), count, flag);
	if (*input == '%')
		ft_put_c(37, count, flag);
}

int			ft_printf(const char *input, ...)
{
	va_list		arg;
	t_printf	flag;
	int			count;

	count = 0;
	va_start(arg, input);
	while (*input)
	{
		if (*input != '%')
			ft_putchar_count(*input, &count);
		else
		{
			input -= -1;
			flag_reset(&flag);
			flag_compare(&input, arg, &flag);
			conv_compare(input, arg, &count, &flag);
		}
		input -= -1;
	}
	va_end(arg);
	return (count);
}
