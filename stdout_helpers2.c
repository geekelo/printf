/*
 * File: stdout_helphers2.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
/**
 * _print_decimal - prints out a integer input passed into it to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success.
 */
int _print_binary(va_list ptr)
{
	char *tmp;
	unsigned int i = 0, ret = 0, num;

	num = va_arg(ptr, unsigned int);
	if (num == 0)
		return (_putchar('0'));

	tmp = convert_to_base(num, 2);
	if (tmp == NULL)
		exit(-1);

	for (; tmp[i]; i++)
		ret += _putchar(tmp[i]);

	return (ret);
}
