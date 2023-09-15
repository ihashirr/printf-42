#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void ft_putstr(char *s)
{
	if (!s)
		return;
	write(1, s, ft_strlen(s));
}
void ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(-nb);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((char)(nbr % 10 + '0'));
}

void printPointerAddress(void *ptr)
{
	unsigned long long int address = (unsigned long long int)ptr; // Cast to an appropriate integer type
	char hex[16] = "0123456789abcdef";
	char result[20] = "0x"; // Assuming 8 bytes for a pointer

	for (int i = 7; i >= 0; i--)
	{
		result[i + 2] = hex[address & 0xf];
		address >>= 4;
	}

	// Print the hexadecimal address without a newline
	for (int i = 0; i < 9; i++)
	{
		write(1, &result[i], 1);
	}

	// Print the hexadecimal address of the variable that the pointer variable is pointing to
	address = (unsigned long long int)ptr;

	for (int i = 7; i >= 0; i--)
	{
		result[i + 12] = hex[address & 0xf];
		address >>= 4;
	}

	// Print the hexadecimal address of the variable that the pointer variable is pointing to
	for (int i = 11; i < 20; i++)
	{
		write(1, &result[i], 1);
	}
}

void ft_printf(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				ft_putnbr(va_arg(arg, int));
			}
			else if (*format == 's')
			{
				ft_putstr(va_arg(arg, char *));
			}
			else if (*format == 'c')
			{
				ft_putchar(va_arg(arg, int));
			}
			else if (*format == 'p')
			{
				printPointerAddress(va_arg(arg, int *));
			}
			else
			{
				ft_putchar('%');
				// ft_putchar(*format);
			}
			format++;
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	va_end(arg);
}
int hexCounter(int num)
{
	int len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
// void convertToHex(int n)
// {
// 	char str[] = "0123456789ABCDEF";

// 	hexCounter(n);
//     char *hex; // Assuming a maximum of 100 characters for the hexadecimal representation
//     int i = 0;
// 	while (n != 0)
// 	{
// 		hex[i] = str[n % 16];
// 		n = n / 16;
// 		i++;
// 	}

// 	// Print the hexadecimal representation in reverse order
// 	for (int j = i - 1; j >= 0; j--)
// 	{
// 		printf("%c", hex[j]);
// 	}
// 	// printf("%c\n\n\n\n", result);
// 	printf("\n\n%X", 42);
// }
#include <stdio.h>

// int	ft_puthexa(unsigned int nb, char *base)
// {
// 	int		i;
// 	int		j;
// 	char	rev[8];

// 	j = 0;
// 	i = 0;
// 	while (nb != 0 || j == 0)
// 	{
// 		rev[j++] = base[nb % 16];
// 		nb /= 16;
// 	}
// 	while (j)
// 		i += ft_putchar(rev[--j]);
// 	return (i);
// }
// void convertToHex(int n,char *str) {
//     // char str[] = "0123456789ABCDEF";
//     // Handle special case for 0
//     if (n == 0) {
//         printf("0");
//         return;
//     }
// 	// while (n!=0)
// 	// {
// 	// 	n%16
// 	// }
	
//     // Initialize to the end of the string
//     char *hex = &str[16];

//     while (n != 0) {
//         hex--; // Move the pointer backward
//         *hex = str[n % 16]; // Assign the hexadecimal character
//         n = n / 16;
//     }

//     // Print the hexadecimal representation directly
//     while (*hex != '\0') {
//         printf("%c", *hex);
//         hex++; // Move the pointer forward
//     }
// }
static int	ft_putnbr_base(long long int n, char *base, int i)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / i > 0)
		c += ft_putnbr_base(n / i, base, i);
	write(1, &base[n % i], 1);
	c++;
	return (c);
}
int main() {
    int num = 42;
    printf("Hexadecimal representation of %d: ", num);
    ft_putnbr_base(num,"0123456789ABCDEF",10);
    printf("\n");
	printf("%x",num);
    return 0;
}



// int main()
// {
// 	int n = 19;
// 	int *num = &n;
// 	int variable = 10;

// // char *hex ;

// // hex ="A";
// // printf("%s",hex);
// 	// void *ptr = &variable;
// 	convertToHex(42);
// 	// printf("%i",convertToHex(9));
// 	// printPointerAddress(&variable);
// 	// printf("%x",n);
// 	// printf("\n\n%u",&variable);
// 	// ft_printf("%s%d%s%%coder%d\n pointer is %p",        "hashir", 42,"malik",92,num);
// 	// printf("\n\n\n\n\n%s%d%s%%coder%d\n pointer is %p","hashir", 42,"malik",92,num);
// 	return 0;
// }
