/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:53:24 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/12/20 14:36:35 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_parsing(va_list argptr, char c);
void	ft_putnbr_base(unsigned int nbr, char *base);
int		ft_skip_flag(char *str, int i);
int 	ft_printf(const char *format, ...);
int		ft_count(char *str);

#endif