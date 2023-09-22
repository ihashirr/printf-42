/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:45:09 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/23 00:44:13 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier(const char *format, va_list arg, int *std_output)
{
	char	ch;

	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(arg, int), "0123456789", 10, std_output);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), std_output);
	else if (*format == 'c')
	{
		ch = va_arg(arg, int);
		*std_output += write(1, &(ch), 1); 
	}
	else if (*format == 'p')
		print_pointer(va_arg(arg, unsigned long long), std_output);
	else if (*format == 'u')
		ft_putnbr_base(va_arg(arg, unsigned), "0123456789", 10, std_output);
	else if (*format == 'x')
		ft_putnbr_base(va_arg(arg, unsigned ), "0123456789abcdef", 16,
			std_output);
	else if (*format == 'X')
		ft_putnbr_base(va_arg(arg, unsigned ), "0123456789ABCDEF", 16,
			std_output);
	else if (*format == '%')
		*std_output += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		stdout_counter;

	stdout_counter = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_specifier(format, arg, &stdout_counter);
		}
		else
		{
			stdout_counter += write(1, format, 1);
			if (stdout_counter == -1)
			{
				return (-1);
			}
		}
		if (*format != '\0')
			format++;
	}
	va_end(arg);
	return (stdout_counter);
}
