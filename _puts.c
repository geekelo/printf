/*
 * File: _putchar.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * _puts - prints out a string of characters passed into it
 * @c: string input
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _puts(char *c)
{
	int len = _strlen(c);

	return (write(1, c, len));
}
