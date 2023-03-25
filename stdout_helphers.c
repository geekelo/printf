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
 *
 * Return: length of byte written on success, -1 otherwise
 */
int _puts(char *c)
{
	int len = _strlen(c);
	char store[1024];
	
	_memcpy(store, c, (unsigned)len);

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

	return (write(1, ptr, len));
}

