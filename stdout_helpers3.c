/*
 * File: stdout_helphers.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"

/**
 * _print_String - prints out a string of characters passed into it to stdout
 *                 replacing non printable characters with \x followed by the
 *                 ASCII code value.
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_String(va_list ptr)
{
	char *p;
	int i = 0, ret = 0;

	p = va_arg(ptr, char *);
	if (p == NULL)
		exit(-1);

	for (; p[i]; i++)
	{
		if (p[i] < 32)
		{
			ret += _putchar('\\');
			ret += _putchar('x');
			ret += _putchar('0');
			ret += _putchar(*convert_to_base(p[i], 17));
		}
		else
		{
			ret += _putchar(p[i]);
		}
	}

	return (ret);
}
