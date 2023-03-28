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
		if ((p[i] < 32 && p[i] > 0) || p[i] >= 127)
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




/**
 * _print_address - prints out memory address of a variable to stdout
 * @pt: va_list pointer
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_address(va_list pt)
{
	uintptr_t num, i = 0;
	char *tmp;
	char ptr[] = "0123456789abcdef";
	int ret = 0;

	if (pt == NULL)
		exit(-1);


	num = (uintptr_t)va_arg(pt, void *);

	tmp = malloc(sizeof(*tmp) * i + 1);
	if (tmp == NULL)
		return (0);

	while (num)
	{
		tmp[i++] = ptr[num % 16];
		tmp = _realloc(tmp, i, i + 1);
		if (tmp == NULL)
			exit(-1);
		num = num / 16;
	}
	tmp[i] = '\0';
	rev_string(tmp);

	ret += _putchar('0');
	ret += _putchar('x');

	for (i = 0; tmp[i]; i++)
		ret += _putchar(tmp[i]);
	free(tmp);
	return (ret);
}




/**
 * _print_rev - prints out a string in reverse to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_rev(va_list ptr)
{
	char *p;
	int i = 0, ret = 0;

	p = va_arg(ptr, char *);
	if (p == NULL)
		exit(-1);

	for (; p[i]; i++)
		;
	for (--i; i >= 0; i--)
		ret += _putchar(p[i]);

	return (ret);
}




/**
 * _print_rot13 - prints out a string encoded in rot13 to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_rot13(va_list ptr)
{
	char *p, *tmp;
	int i = 0, ret = 0;

	p = va_arg(ptr, char *);
	if (p == NULL)
		exit(-1);

	for (; p[i]; i++)
		;

	tmp = malloc(sizeof(*tmp) * i + 1);
	_memcpy(tmp, p, i + 1);
	rot13(tmp);

	for (i = 0; tmp[i]; i++)
		ret += _putchar(p[i]);

	free(tmp);
	return (ret);
}

