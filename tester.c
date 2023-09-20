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

#include "stdarg.h"
#include "unistd.h"
void fwprintf(char *format, ...)
{
	va_list arg;

	va_start(arg, format);

	while (*format)
	{
		if (*format)
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(arg, int); // Retrieve the character as an int
				write(1, &(va_arg(arg, int)), 1);
			}
		}
	}
}

int main()
{
	fwprintf("%c", 'c');
}