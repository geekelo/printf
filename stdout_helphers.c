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
	int ret = 0;

	if (c < 0)
		return (-1);
	store[0] = c;


	ret += write(1, store, 1);
	return (ret);
}




/**
 * _puts - prints out a string of characters passed into it to stdout
 * @c: string input
 * @format: describes how the string should be printed out:
 *          0 - normal string output,
 *          1 - reversed string output,
 *          2 - none printable characters replaced with \x,
 *          3 - rot13'ed output.
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _puts(char *c, int format)
{
	char store[1024], *ptr;
	int len, ret = 0;

	len = _strlen(c);

	if (c == NULL)
	{
		c = "(nil)";
		_memcpy(store, c, 5);
		return (write(1, store, 5));
	}

	switch (format)
	{
		case 0:
			_memcpy(store, c, (unsigned int)len);
			break;
		case 1:
			ptr = malloc(sizeof(*ptr) * (len + 1));
			if (ptr == NULL)
				return (-1);

			_memcpy(ptr, c, len + 1);
			rev_string(ptr);
			_memcpy(store, ptr, (unsigned int)len);
			free(ptr);
			break;
		case 3:
			ptr = malloc(sizeof(*ptr) * (len + 1));
			if (ptr == NULL)
				return (-1);

			_memcpy(ptr, c, len + 1);
			rot13(ptr);
			_memcpy(store, ptr, (unsigned int)len);
			free(ptr);
			break;
	}
	ret += write(1, store, len);

	return (ret);
}




/**
 * _print_strings - prints out a string of characters passed into it to stdout
 * @c: string input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_strings(char *c)
{
	int len, ret = 0;
	char store[1024];

	if (c != NULL)
	{
		len = _strlen(c);
		_memcpy(store, c, (unsigned int)len);
		free(c);

		ret += write(1, store, len);
	}
	return (ret);
}



/**
 * print_number - prints out a number to stdout
 * @num: number input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int print_number(int num)
{
	char *ptr = _itoa(num);
	int len, ret = 0;
	char store[1024];

	if (ptr != NULL)
	{
		len = _strlen(ptr);
		_memcpy(store, ptr, (unsigned int)len);
		free(ptr);

		ret += write(1, store, len);
	}

	return (ret);
}




/**
 * print_address - prints out address of a variable to stdout
 * @address: address input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int print_address(void *address)
{
	uintptr_t num, i = 0, len = 12;
	char store[1024], *tmp;
	char ptr[] = "0123456789abcdef";
	int ret = 0;

	if (address == NULL)
		return (0);


	num = (uintptr_t)address, i = 0, len = 12;

	tmp = malloc(sizeof(*tmp) * i + 1);
	if (tmp == NULL)
		return (0);

	while (num)
	{
		tmp[i++] = ptr[num % 16];
		tmp = _realloc(tmp, i, i + 1);
		if (tmp == NULL)
			return (0);
		num = num / 16;
	}
	tmp[i] = '\0';
	rev_string(tmp);

	_memcpy(store, tmp, len);
	free(tmp);

	ret += (_puts("0x", 0) + write(1, store, len));

	return (ret);
}
