#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>



int ft_printf(const char *format, ...);
void ft_putnbr_base(long long n, char *base, int i);
void ft_putstr(char *s, int *std_output);
void ft_putchar(char c);
void print_pointer(unsigned long long ptr);

#endif