/*
 * File: _putchar.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>



/**
 * _printf - prints to standard output
 * @c: string input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0, ret = 0;
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
			return (_puts(va_arg(ptr, char *)));
		case 'd':
			return (print_number(va_arg(ptr, int)));
/*		case 'o':
			char *o = base_converter(va_arg(ptr, int), 8);
			return (_puts(o));
		case 'x':
			char *x = base_converter(va_arg(ptr, int), 16);
			return (_puts(x));
*/		default:
			if (s != '\0')
			{
				_putchar('%');
				_putchar(s);
			}
			else
			{
				_puts("invalid format specifier\n");
			}
	}
	return (0);
}

