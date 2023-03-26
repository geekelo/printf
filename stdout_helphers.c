/*
 * File: stdout_helphers.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>

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
	int len = _strlen(c);

	switch (format)
	{
		case 0:
			_memcpy(store, c, (unsigned int)len);
			break;
		case 1:
			ptr = malloc(sizeof(*ptr) * (len + 1));

			_memcpy(ptr, c, len + 1);
			rev_string(ptr);
			_memcpy(store, ptr, (unsigned int)len);
			free(ptr);
			break;
		case 2:
			ptr = malloc(sizeof(*ptr) * len);

			non_printable(ptr, c, len);
			_memcpy(store, ptr, len);
			free(ptr);
			break;
		case 3:
			ptr = malloc(sizeof(*ptr) * len);

			rot13(ptr, c, len);
			_memcpy(store, ptr, len);
			free(ptr);
			break;
	}


	return (write(1, store, len));
}




/**
 * _print_strings - prints out a string of characters passed into it to stdout
 * @c: string input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _print_strings(char *c)
{
	int len = _strlen(c);
	char store[1024];

	_memcpy(store, c, (unsigned int)len);
	free(c);

	return (write(1, store, len));
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
	int len = _strlen(ptr);
	char store[1024];

	_memcpy(store, ptr, (unsigned int)len);
	free(ptr);

	return (write(1, store, len));
}




/**
 * print_address - prints out address of a variable to stdout
 * @address: address input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int print_address(void *address)
{
	uintptr_t num = (uintptr_t)address, i = 0, len = 12;
	char store[1024];

	char *tmp;
	char ptr[] = "0123456789abcdef";

	tmp = malloc(sizeof(*tmp) * i + 1);

	while (num)
	{
		tmp[i++] = ptr[num % 16];
		tmp = _realloc(tmp, i, i + 1);
		num = num / 16;
	}
	tmp[i] = '\0';
	rev_string(tmp);

	_memcpy(store, tmp, len);
	free(tmp);

	return (_puts("0x", 0) + write(1, store, len));
}
