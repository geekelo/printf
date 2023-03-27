/*
 * File: stdout_helphers.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"

/**
 * _putchar - prints out a single character passed into it
 * @c: character input
 *
 * Return: 1 on success, -1 otherwise
 */
int _putchar(char c)
{
	char store[1024];

	store[0] = c;

	return (write(1, store, 1));
}




/**
 * _print_char - prints a character passed into it to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_char(va_list ptr)
{
	char c;

	if (ptr == NULL)
		return (0);
	c = va_arg(ptr, int);

	return (_putchar(c));
}




/**
 * _print_string - prints out a string of characters passed into it to stdout
 * @ptr: va_list pointer
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_string(va_list ptr)
{
	char *p;
	int i = 0, ret = 0;

	if (ptr == NULL)
		return (0);

	p = va_arg(ptr, char *);
	if (p == NULL)
		return (0);

	for (; p[i]; i++)
		ret += _putchar(p[i]);

	return (ret);
}




/**
 * _print_percent - prints out % symbol to stdout
 * @ptr: va_list pointer
 *
 * Return: 1
 */
int _print_percent(va_list ptr)
{
	if (ptr == NULL)
		return (0);

	return (_putchar('%'));
}
