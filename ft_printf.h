/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:53:24 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/12/23 15:04:19 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putnbr(int n, int count);
int		ft_putstr(char *s, int count);
int		ft_strlen(const char *s);
int		ft_parsing(va_list argptr, char c, int count);
int		ft_parsing_2(va_list argptr, char c, int count);
int		ft_putnbr_base(unsigned long long int nbr, char *base, int count);
int		ft_skip_flag(char *str, int i);
int		ft_printf(const char *format, ...);

#endif