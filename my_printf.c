/*
 * File: _putchar.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
#include <stdio.h>

/**
 * _printf - prints to standard output
 * @format: string input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _printf(const char *format, ...)
{
	int i = 0, ret = 0, check, tmp;
	va_list ptr;

	if (format == NULL || ptr == NULL)
		return (-1);

	va_start(ptr, format);

	for (; format[i]; i++)
	{
		check = 0, tmp = 0;

		if (format[i] == '%')
			check = length_check(format[i + 1], &tmp);

		if (format[i] == '%' && format_specifier(format[i + 1 + tmp]))
		{
			ret += format_specifier(format[i + 1 + tmp])(ptr, check);
			i += tmp + 1;
		}
		else
		{
			ret += _putchar(format[i]);
		}
	}

	va_end(ptr);
	return (ret);

}




/**
 * format_specifier - handles format type from _printf()
 * @s: format specifier
 *
 * Return: length of byte accessed by ptr, 0 otherwise
 */
int (*format_specifier(char s))(va_list, int)
{
	specifiers ops[] = {
		{'c', _print_char},
		{'s', _print_string},
		{'%', _print_percent},
		{'d', _print_decimal},
		{'i', _print_decimal},
		{'b', _print_binary},
		{'u', _print_unsigned},
		{'o', _print_octal},
		{'x', _print_hex},
		{'X', _print_HEX},
		{'S', _print_String},
		{'p', _print_address},
		{'r', _print_rev},
		{'R', _print_rot13},
		{'\0', NULL}
	};
	int i = 0;

	for (; ops[i].specifier; i++)
	{
		if (ops[i].specifier == s)
			return (ops[i].f);
	}

	return (NULL);
}

/**
 * length_check - checks for LONG or SHORT specifier.
 * @s: input string character
 * @tmp: value is increamented if true
 *
 * Return: either LONG or SHORT
 */


int length_check(char s, __attribute__((unused)) int *tmp)
{
	int *ptr = tmp;

	if (s == 'l')
	{
		*ptr += 1;
		return (LONG);
	}
	else if (s == 'h')
	{
		*ptr += 1;
		return (SHORT);
	}

	return (0);
}
