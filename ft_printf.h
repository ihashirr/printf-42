/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:07:26 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/22 03:21:37 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr_base(long long n, char *base, int i, int *std_output);
void	ft_putstr(char *s, int *std_output);
void	print_pointer(unsigned long long p, int *std_output);
void	ft_putnbr(long n, char *base, int i, int *std_output);
#endif