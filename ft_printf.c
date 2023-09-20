// #include "ft_printf.h"
// #include "limits.h"
// static void ft_specifier(const char *format, va_list arg, int *std_output)
// {
// 	if (*format == 'd' || *format == 'i')
// 		ft_putnbr_base(va_arg(arg, int), "0123456789", 10, std_output);
// 	else if (*format == 's')
// 		ft_putstr(va_arg(arg, char *), std_output);
// 	else if (*format == 'c'){
// 		char ch = va_arg(arg, int);
// 		*std_output += write(1, &(ch), 1); // Use %c format specifier
// 	}
// 	else if (*format == 'p'){
// 		print_pointer(va_arg(arg, long long), std_output);

// 	}
// 	else if (*format == 'u')
// 		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789", 10, std_output);
// 	else if (*format == 'x')
// 		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789abcdef", 16, std_output);
// 	else if (*format == 'X')
// 		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789ABCDEF", 16, std_output);
// 	else if (*format == '%')
// 		*std_output += write(1, "%", 1);
// }
// int ft_printf(const char *format, ...)
// {
// 	va_list arg;
// 	int stdout_counter;

// 	stdout_counter = 0;
// 	va_start(arg, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			ft_specifier(format, arg, &stdout_counter);
// 		}
// 		else
// 			stdout_counter += write(1, format, 1);
// 		format++;
// 	}
// 	va_end(arg);
// 	return stdout_counter;
// }

// // int main()
// // {
// // 	// char *num = "hashir";
// // 	// ft_printf("%i ", ft_printf("\tmy printf: %s\t%d\t%i\t%p\t%u\t%X\t%x\t", NULL, 1234, -123, num, UINT_MAX + 1, UINT_MAX + 2, 10));
// // 	ft_printf("%c\n",'c');
// // 	// printf("%i ", printf("\tor printf: %s\t%d\t%i\t%p\t%u\t%X\t%x\t", NULL, 1234, -123, num, UINT_MAX + 1, UINT_MAX +2, 10));
// // }

#include "ft_printf.h"

static int ft_printf_p(unsigned long n, char *base, int i, int flag);
static int ft_putnbr_base(long long int n, char *base, int i);
static int ft_printf_s(char *s);
static int ft_call_print(char s, va_list arg);
int ft_printf(const char *s, ...);

static int ft_printf_p(unsigned long n, char *base, int i, int flag)
{
	int c;

	c = 0;
	if (!n && flag == 0)
		return (ft_printf_s("(nil)"));
	if (flag == 0)
		c += ft_printf_s("0x");
	if (n / i > 0)
		c += ft_printf_p(n / i, base, i, ++flag);
	write(1, &base[n % i], 1);
	c++;
	return (c);
}

static int ft_putnbr_base(long long int n, char *base, int i)
{
	int c;

	c = 0;
	if (n < 0)
	{
		c += ft_printf_s("-");
		n = -n;
	}
	if (n / i > 0)
		c += ft_putnbr_base(n / i, base, i);
	write(1, &base[n % i], 1);
	c++;
	return (c);
}

static int ft_printf_s(char *s)
{
	int i;

	if (!s)
		return (ft_printf_s("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int ft_call_print(char s, va_list arg)
{
	int i;
	int j;

	i = 1;
	if (s == 'c')
	{
		j = va_arg(arg, int);
		write(1, &j, 1);
	}
	else if (s == 's')
		i = ft_printf_s(va_arg(arg, char *));
	else if (s == 'd' || s == 'i')
		i = ft_putnbr_base(va_arg(arg, int), "0123456789", 10);
	else if (s == '%')
		write(1, "%%", 1);
	else if (s == 'x')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", 16);
	else if (s == 'X')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", 16);
	else if (s == 'u')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", 10);
	else if (s == 'p')
		i = ft_printf_p(va_arg(arg, long int), "0123456789abcdef", 16, 0);
	return (i);
}

int ft_printf(const char *s, ...)
{
	va_list arg;
	int chars;
	int i;

	chars = 0;
	i = -1;
	va_start(arg, s);
	while (s && s[++i])
	{
		if (s[i] != '%')
		{
			chars++;
			write(1, &s[i], 1);
		}
		else
			chars += ft_call_print(s[++i], arg);
	}
	va_end(arg);
	return (chars);
}