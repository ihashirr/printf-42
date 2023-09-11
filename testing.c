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


void printPointerAddress(void *ptr) {
   unsigned long long int address = (unsigned long long int)ptr; // Cast to an appropriate integer type
  char hex[16] = "0123456789abcdef";
  char result[20] = "0x"; // Assuming 8 bytes for a pointer

  for (int i = 7; i >= 0; i--) {
    result[i + 2] = hex[address & 0xf];
    address >>= 4;
  }

  // Print the hexadecimal address without a newline
  for (int i = 0; i < 9; i++) {
    write(1, &result[i], 1);
  }

  // Print the hexadecimal address of the variable that the pointer variable is pointing to
  address = (unsigned long long int) ptr;

  for (int i = 7; i >= 0; i--) {
    result[i + 12] = hex[address & 0xf];
    address >>= 4;
  }

  // Print the hexadecimal address of the variable that the pointer variable is pointing to
  for (int i = 11; i < 20; i++) {
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
			if (*format == 'd' ||*format == 'i' )
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

int main()
{
	int n =12;
	int *num = &n;
int variable = 10;

void *ptr = &variable;

// printPointerAddress(&variable);
printf("%p",ptr);
printf("\n\n%u",&variable);
	// ft_printf("%s%d%s%%coder%d\n pointer is %p",        "hashir", 42,"malik",92,num);
	// printf("\n\n\n\n\n%s%d%s%%coder%d\n pointer is %p","hashir", 42,"malik",92,num);
	return 0;
}
