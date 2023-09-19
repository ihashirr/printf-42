#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}
static int ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
void ft_putstr(char *s, int * std_output)
{
	*std_output = ft_strlen(s);
	if (!s)
		return;
	write(1, s, ft_strlen(s));
}
 void ft_putnbr_base(long long n, char *base, int i)
{

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / i > 0)
		ft_putnbr_base(n / i, base, i);
	write(1, &base[n % i], 1);

}

void print_pointer(unsigned long long ptr)
{

	write(1, "0x", 2);
	ft_putnbr_base(ptr, "0123456789abcdef", 16);
}
