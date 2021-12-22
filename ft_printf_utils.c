/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:20:27 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/12/22 16:55:02 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s, int count)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i + count);
}

int	ft_putnbr(int n, int count)
{
	if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return (count + 10);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (count + 11);
	}
	else if (n < 0)
	{
		count = count + ft_putchar('-');
		count = ft_putnbr(-n, count);
	}
	else if (n >= 10)
	{
		count = ft_putnbr(n / 10, count);
		count = count + ft_putchar(n % 10 + 48);
	}
	else
		count = count + ft_putchar(n + 48);
	return (count);
}

int	ft_putnbr_base(unsigned long long int nbr, char *base, int count)
{
	unsigned long long int	size;

	size = ft_strlen(base);
	if (nbr <= size)
		count = count + ft_putchar(base[nbr % size]);
	else
	{
		count = ft_putnbr_base(nbr / size, base, count);
		count = count + ft_putchar(base[nbr % size]);
	}
	return (count);
}
