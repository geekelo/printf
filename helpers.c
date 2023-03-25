/*
 * File: _itoa.c
 * Author: Chidiadi E. Nwosu
 * Desc: file containing helper functions for printf rewrite project
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _itoa - convert a positive integer to string
 * @num: integr to be converted
 *
 * Return: converted int value
 */
char *_itoa(int num)
{
	char *output = malloc(1);
	char tmp;
	unsigned int i, len = 0;

	while (num)
	{
		output[len++] = num % 10 + '0';
		num = num / 10;
		output = _realloc(output, len, len + 1);
	}
	output[len] = '\0';
	for (i = 0; i < len / 2; i++)
	{
		tmp = output[i];
		output[i] = output[len - i -1];
		output[len - i - 1] = tmp;
	}
	return (output);
}



/**
 * _atoi - convert a string to an integer
 * @s: string to be converted
 *
 * Return: converted int value
 */
int _atoi(char *s)
{
	int c_nve = 0;
	int i = 0;
	unsigned int result = 0;

	while ((s[i] != '\0'))
	{
		if (s[i] >= '0' && s[i] <= '9')
			break;
		else if (s[i] == '-')
			c_nve++;

		i++;
	}

	while ((s[i] != '\0'))
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			break;

		result = result * 10 + s[i] - '0';
		i++;
	}

	if ((c_nve % 2) != 0)
		result = -result;

	return (result);
}




/**
 * _strlen - returns the length of a string
 * @s: string length to return
 *
 * Return: void
 */
int _strlen(char *s)
{
	int count = 0;

	while ((*(s++) != '\0'))
		count++;

	return (count);
}



/**
 * rev_string - reverses a string
 * @s: string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int count = 0;
	int i;

	while ((s[count] != '\0'))
		count++;

	for (i = 0; i < count / 2; i++)
	{
		char tmp = *(s + i);
		*(s + i) = *(s + (count - 1 - i));
		*(s + (count - 1 - i)) = tmp;
	}
}



/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 *
 * Return: pointer to the allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i = 0;

	if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}
	else
	{
		char *cast_p, *cast_ptr;

		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		cast_p = (char *)p;
		cast_ptr = (char *)ptr;
		for (; i < old_size; i++)
			cast_p[i] = cast_ptr[i];

		cast_p = (void *)cast_p;

		free(cast_ptr);
		return (cast_p);
	}
}
