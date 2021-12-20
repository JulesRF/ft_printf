/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:40:49 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/12/20 15:21:29 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == 2147483647)
		write(1, "2147483647", 10);
	else if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

void	ft_putstr(char *s)
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
}

int	ft_count(char *str)
{
	int	i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res++;
			if (str[i + 1] == '%')
				res--;
		}
		i++;
	}
	if (!res)
		ft_putstr(str);
	return (res);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	size;

	size = 16;
	if (nbr <= size)
		ft_putchar(base[nbr % size]);
	else
	{
		ft_putnbr_base(nbr / size, base);
		ft_putchar(base[nbr % size]);
	}
}

void	ft_parsing(va_list argptr, char c)
{
	char			*s;
	char			chara;
	int				d;
	unsigned int	u;
	void			*ptr;
	
	if (c == 's')
	{
		s = va_arg(argptr, char *);
		ft_putstr(s);
	}
	else if (c == 'c')
	{
		chara = va_arg(argptr, int);
		ft_putchar(chara);
	}
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(argptr, int);
		ft_putnbr(d);
	}
	else if (c == 'u')
	{
		d = va_arg(argptr, int);
		u = (unsigned int) d;
		ft_putnbr(u);
	}
	// else if (c == 'p')
	// {
	// 	s = va_arg(argptr, char *);
	// 	ft_putstr((char *)s);
	//}
	else if (c == 'x')
	{
		u = va_arg(argptr, int);
		ft_putnbr_base(u, "0123456789abcdef");
	}
	else if (c == '%')
		ft_putchar('%');
}

int	ft_skip_flag(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
		|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == '%')
			return (i + 1);
		i++;
	}
	return (0);
}

int ft_printf(const char *format, ...)
{
	int		arg;
	int 	count;
	int		i;
	va_list	argptr;
	
	arg = ft_count((char *)format);
	count = 0;
	i = 0;
	va_start(argptr, arg);
	while (count < arg)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				ft_parsing(argptr, format[i + 1]);
				i = ft_skip_flag((char *)format, i + 1);
				count++;
			}
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(argptr);
	return (0);
}

int main()
{
	printf("Salut mon N-word\n");
	ft_printf("Salut mon N-word\n");	
}