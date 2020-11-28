/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:12:35 by jelvan-d          #+#    #+#             */
/*   Updated: 2019/12/30 14:36:58 by jelvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		ft_strlen_nbr(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_strlen_s(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
