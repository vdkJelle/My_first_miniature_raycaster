/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 09:28:14 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/22 15:55:23 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdio.h>

static void	ft_hex_pad(unsigned long n, int len, int *count, t_printf *flag)
{
	if (flag->maxwidth > 0 && (flag->maxwidth <= len))
		flag->width -= (flag->maxwidth);
	else if (flag->precision != 1)
		flag->width -= len;
	else if (flag->precision == 1 && n != 0)
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

static void	ft_print_address(unsigned long n, int *count)
{
	unsigned long	tmp;

	if (n > 15)
		ft_print_address(n / 16, count);
	tmp = n % 16;
	if (tmp > 9 && tmp < 16)
		ft_putchar_count((n % 16) + 'W', count);
	else
		ft_putchar_count((n % 16) + '0', count);
}

void		ft_put_p(unsigned long n, int *count, t_printf *flag)
{
	int	numlen;

	numlen = ft_strlen_hex(n);
	flag->width -= 2;
	if (flag->width > 0 && flag->reverse != 1)
		ft_hex_pad(n, numlen, count, flag);
	write(1, "0x", 2);
	*count -= -2;
	if (flag->precision != 1)
		ft_print_address(n, count);
	if (flag->precision == 1 && flag->maxwidth == -2 && n != 0)
		ft_print_address(n, count);
	if (flag->width > 0)
		ft_reverse_pad(numlen, count, flag);
}
