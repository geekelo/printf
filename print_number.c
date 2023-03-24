/*
 * File: print_number.c
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
int print_number(int num)
{
	char *ptr = _itoa(num);
	int len = _strlen(ptr);

	return (write(1, ptr, len));
}
