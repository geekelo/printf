/*
 * File: stdout_helphers2.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
/**
 * _print_binary - prints out a integer in binary to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success.
 */
int _print_binary(va_list ptr, __attribute__((unused)) int check)
{
	char *tmp;
	unsigned long i = 0, ret = 0, num;

	if (check == LONG)
		num = va_arg(ptr, unsigned long);
	else
		num = va_arg(ptr, unsigned int);
	if (num == 0)
		return (_putchar('0'));

	tmp = convert_to_base(num, 2, check);
	if (tmp == NULL)
		exit(-1);

	for (; tmp[i]; i++)
		ret += _putchar(tmp[i]);

	return (ret);
}




/**
 * _print_unsigned - prints out unsigned integer to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success.
 */
int _print_unsigned(va_list ptr, __attribute__((unused)) int check)
{
	char *tmp;
	unsigned long i = 0, ret = 0, num;

	if (check == LONG)
		num = va_arg(ptr, unsigned long);
	else
		num = va_arg(ptr, unsigned int);
	if (num == 0)
		return (_putchar('0'));

	tmp = convert_to_base(num, 10, check);
	if (tmp == NULL)
		exit(-1);

	for (; tmp[i]; i++)
		ret += _putchar(tmp[i]);

	return (ret);
}




/**
 * _print_octal - prints out a integer in octal value to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success.
 */
int _print_octal(va_list ptr, __attribute__((unused)) int check)
{
	char *tmp;
	unsigned long i = 0, ret = 0, num;

	if (check == LONG)
		num = va_arg(ptr, unsigned long);
	else
		num = va_arg(ptr, unsigned int);
	if (num == 0)
		return (_putchar('0'));

	tmp = convert_to_base(num, 8, check);
	if (tmp == NULL)
		exit(-1);

	for (; tmp[i]; i++)
		ret += _putchar(tmp[i]);

	return (ret);
}




/**
 * _print_hex - prints out a integer in hexadecimal to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success.
 */
int _print_hex(va_list ptr, __attribute__((unused)) int check)
{
	char *tmp;
	unsigned long i = 0, ret = 0, num;

	if (check == LONG)
		num = va_arg(ptr, unsigned long);
	else
		num = va_arg(ptr, unsigned int);

	if (num == 0)
		return (_putchar('0'));

	tmp = convert_to_base(num, 16, check);
	if (tmp == NULL)
		exit(-1);

	for (; tmp[i]; i++)
		ret += _putchar(tmp[i]);

	return (ret);
}




/**
 * _print_HEX - prints out a integer in HEX to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success.
 */
int _print_HEX(va_list ptr, __attribute__((unused)) int check)
{
	char *tmp;
	unsigned long i = 0, ret = 0, num;

	if (check == LONG)
		num = va_arg(ptr, unsigned long);
	else
		num = va_arg(ptr, unsigned int);


	if (num == 0)
		return (_putchar('0'));

	tmp = convert_to_base(num, 17, check);
	if (tmp == NULL)
		exit(-1);

	for (; tmp[i]; i++)
		ret += _putchar(tmp[i]);

	return (ret);
}
