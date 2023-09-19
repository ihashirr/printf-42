#include "ft_printf.h"

static void ft_specifier(const char *format, va_list arg ,int *std_output)
{
	*std_output  = 1;
	if (*format == 'd' || *format == 'i')
		ft_putnbr_base(va_arg(arg, long long), "0123456789", 10);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), std_output);
	else if (*format == 'c')
		ft_putchar(va_arg(arg, int));
	else if (*format == 'p')
		print_pointer(va_arg(arg, unsigned long long));
	else if (*format == 'u')
		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789", 10);
	else if (*format == 'x')
		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789abcdef", 16);
	else if (*format == 'X')
		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789ABCDEF", 16);
	else if (*format == '%')
		ft_putchar('%');
}
int ft_printf(const char *format, ...)
{
	va_list arg;
	int stdout_counter;

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
			ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return stdout_counter;
}

int main()
{
	char * num = 0;
ft_printf("%s\thashirghiu",num );
}
