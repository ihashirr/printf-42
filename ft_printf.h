#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>

int ft_printf(const char *format, ...);
int ft_putnbr_base(long long n, char *base, int i);
int ft_putstr(char *s);
int ft_putchar(char c);
int print_pointer(unsigned long long ptr);

#endif