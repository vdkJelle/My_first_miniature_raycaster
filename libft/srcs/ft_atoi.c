/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:24:11 by jelvan-d      #+#    #+#                 */
/*   Updated: 2021/10/20 13:24:14 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static long int	ft_fkatoi(const char *str, unsigned long int res, int sign)
{
	while (*str >= '0' && *str <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
					&& (*str - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
					&& (*str - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = ft_fkatoi(str, res, sign);
	return (res * sign);
}
