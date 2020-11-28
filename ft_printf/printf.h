/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:04:10 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/27 11:20:53 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

typedef struct	s_printf
{
	int			width;
	int			reverse;
	int			padding;
	int			precision;
	int			maxwidth;
	int			sign;
}				t_printf;

int				ft_printf(const char *input, ...);
void			ft_putchar_count(char c, int *count);
void			ft_putnbr_hex_low(unsigned long n, int *count, t_printf *flag);
void			ft_putnbr_hex_up(unsigned long n, int *count, t_printf *flag);
void			ft_put_s(char *s, int *count, t_printf *flag);
void			ft_put_u(unsigned int n, int *count, t_printf *flag);
void			ft_put_p(unsigned long n, int *count, t_printf *flag);
void			ft_putnbr(long long n, int *count, t_printf *flag);
int				ft_get_width(const char ***input, va_list arg, t_printf *flag);
int				ft_strlen_s(char *s);
int				ft_strlen_nbr(long long n);
int				ft_strlen_hex(unsigned long n);
void			ft_put_c(int c, int *count, t_printf *flag);
void			ft_pad(int len, int *count, t_printf *flag);
void			ft_reverse_pad(int len, int *count, t_printf *flag);

#endif
