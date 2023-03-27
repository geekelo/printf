/*
 * File: _putchar.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"


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

	if (format == NULL)
		return (-1);

	va_start(ptr, format);

	for (; format[i]; i++)
	{
		if (format[i] == '%' && format_handler(format[i + 1]))
			ret += format_handler(format[i++ + 1])(ptr);
		else
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
int (*format_handler(char s))(va_list)
{
	handler ops[] = {
		{'c', _print_char},
		{'s', _print_string},
		{'%', _print_percent},
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
