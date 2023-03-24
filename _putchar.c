/*
 * File: _putchar.c
 * Author: Chidiadi E. Nwosu
 */

#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints out a single character passed into it
 * @c: character input
 *
 * Return: 1 on success, -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
