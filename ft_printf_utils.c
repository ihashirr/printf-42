/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:55:01 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/22 22:48:36 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *std_output)
{
	if (!s)
	{
		*std_output += write(1, "(null)", 6);
		return ;
	}
	while (*s != '\0')
	{
		*std_output += write(1, s, 1);
		s++;
	}
}

void	ft_putnbr_base(long long n, char *base, int i, int *std_output)
{
	unsigned long long	num;

	num = n;
	if (num / i > 0)
		ft_putnbr_base(num / i, base, i, std_output);
	*std_output += write(1, &base[num % i], 1);
}

void	ft_putnbr( long n, char *base, int i, int *std_output)
{
	if (n < 0)
	{
		*std_output += write(1, "-", 1);
		n = -n;
	}
	if (n / i > 0)
		ft_putnbr(n / i, base, i, std_output);
	*std_output += write(1, &base[n % i], 1);
}

void	print_pointer(unsigned long long p, int *std_output)
{
	*std_output += write(1, "0x", 2);
	if (p == 0)
	{
		*std_output += write(1, "0", 1);
		return ;
	}
	ft_putnbr_base(p, "0123456789abcdef", 16, std_output);
}
