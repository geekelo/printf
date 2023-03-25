/*
 * File: _putchar.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>



/**
 * _printf - prints to standard output
 * @format: string input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _printf(const char *format, ...)
{
	int i = 0, ret = 0;
	va_list ptr;

	va_start(ptr, format);

	for (; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			ret += format_handler(ptr, format[i + 1]);
			i++;
			continue;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ret += _putchar('%');
			i++;
			continue;
		}
		ret += _putchar(format[i]);
	}

	va_end(ptr);
	return (ret);

}




/**
 * format_handler - handles format type from _printf()
 * @ptr: va_list ptr
 * @s: format specifier
 *
 * Return: length of byte accessed by ptr, 0 otherwise
 */
int format_handler(va_list ptr, char s)
{
	switch (s)
	{
		case 'c':
			return (_putchar(va_arg(ptr, int)));
		case 's':
			return (_puts(va_arg(ptr, char *), 0));
		case 'd':
			return (print_number(va_arg(ptr, int)));
		case 'i':
			return (print_number(convert_to_10(va_arg(ptr, int), 10)));
		case 'b':
			return (_print_strings(convert_to_base(va_arg(ptr, unsigned int), 2)));
		case 'u':
			return (_print_strings(convert_to_base(va_arg(ptr, unsigned int), 10)));
		case 'o':
			return (_print_strings(convert_to_base(va_arg(ptr, unsigned int), 8)));
		case 'x':
			return (_print_strings(convert_to_base(va_arg(ptr, unsigned int), 16)));
		case 'X':
			return (_print_strings(convert_to_base(va_arg(ptr, unsigned int), 17)));
		case 'r':
			return (_puts(va_arg(ptr, char *), 1));
		default:
			if (s != '\0')
			{
				_putchar('%');
				_putchar(s);
			}
			else
			{
				_puts("invalid format specifier\n", 0);
			}
	}
	return (0);
}

