#include "ft_printf.h"

static void ft_specifier(const char *format, va_list arg ,int *std_output)
{
	if (*format == 'd' || *format == 'i')
		*std_output += ft_putnbr_base(va_arg(arg, long long), "0123456789", 10);
	else if (*format == 's')
		*std_output += ft_putstr(va_arg(arg, char *));
	else if (*format == 'c')
		*std_output += ft_putchar(va_arg(arg, int));
	else if (*format == 'p')
		*std_output += print_pointer(va_arg(arg, unsigned long long));
	else if (*format == 'u')
		*std_output += ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789", 10);
	else if (*format == 'x')
		*std_output += ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789abcdef", 16);
	else if (*format == 'X')
		*std_output += ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789ABCDEF", 16);
	else if (*format == '%')
		*std_output += ft_putchar('%');
}
int ft_printf(const char *format, ...)
{
	va_list arg;
	int std_output;

	std_output = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_specifier(format, arg, &std_output);
		}
		else
			std_output += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return std_output;
}
int main() {
    int num = 42;
	ft_printf("%d\n", num);
	return 0;
}
