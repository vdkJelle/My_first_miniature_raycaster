/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:27:22 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/27 16:42:50 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_u(unsigned int n, int *count)
{
	if (n > 9)
		ft_print_u(n / 10, count);
	ft_putchar_count((n % 10) + '0', count);
}

static void	ft_pad_u(int *count, t_printf *flag)
{
	while (flag->width > 0)
	{
		ft_putchar_count(' ', count);
		(flag->width)--;
	}
}

static void	ft_reverse_pad_u(int len, int *count, t_printf *flag)
{
	if (flag->maxwidth == -2)
		flag->width -= len;
	while (flag->width > 0)
	{
		ft_putchar_count(' ', count);
		(flag->width)--;
	}
}

static void	ft_resolve_u(int numlen, int *count, t_printf *flag)
{
	int	tmp;

	tmp = numlen;
	if (flag->maxwidth > numlen)
		numlen = flag->maxwidth;
	if (flag->maxwidth >= 0 &&
		(flag->maxwidth <= numlen || flag->maxwidth < flag->width))
		flag->width -= numlen;
	if (flag->width && flag->reverse != 1 && (flag->padding != 1
		|| flag->maxwidth != -2))
		ft_pad_u(count, flag);
	while (flag->maxwidth > tmp || (flag->width > numlen && flag->padding == 1))
	{
		ft_putchar_count('0', count);
		tmp -= -1;
		if (flag->padding == 1 && flag->reverse != 1)
			(flag->width)--;
	}
}

void		ft_put_u(unsigned int n, int *count, t_printf *flag)
{
	int				numlen;

	numlen = ft_strlen_nbr(n);
	if (flag->precision == 1 && n == 0 &&
		(flag->maxwidth == -2 || flag->maxwidth == 0))
		numlen = 0;
	if (flag->maxwidth == -2 && flag->reverse != 1 && flag->padding != 1)
		flag->width -= numlen;
	ft_resolve_u(numlen, count, flag);
	if (n != 0 || flag->precision != 1 ||
		(flag->maxwidth != -2 && flag->maxwidth != 0))
		ft_print_u(n, count);
	if (flag->width > 0)
		ft_reverse_pad_u(numlen, count, flag);
}
