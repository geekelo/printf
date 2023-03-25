/*
 * File: 1-memcpy.c
 * Author: Chidiadi E. Nwosu
 */
#include "main.h"
#include <stdlib.h>

/**
 * _memcpy - copies memory area
 * @dest: memory area destination
 * @src: memory area source
 * @n: number of bytes
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = src[i];
	return (dest);
}



/**
 * convert_to_10 - converts a positive integer to base 10
 * @num: input integer
 *
 * Return: converted number
 */
int convert_to_10(int num, int base)
{
	char *s_num = _itoa(num);
	int len = _strlen(s_num), res = 0, power = 1, i;

	for (i = len - 1; i >= 0; i--)
	{
		res += (s_num[i] - '0') * power;
		power *= base;
	}

	free(s_num);
	return (res);
}



/**
 * convert_to_base - converts a positive integer from base 10
 * @num: input integer
 * @base: base to convert to.
 *
 * Return: converted number in strings
 */
char *convert_to_base(unsigned int num, unsigned int base)
{
	char *tmp, *ptr;
	char base_x[] = "0123456789abcdef";
	char base_X[] = "0123456789ABCDEF";
	unsigned int i = 0;

	if (num == 0 || base == 0)
		return (NULL);

	if (base == 17)
	{
		ptr = base_X;
		base = 16;
	}
	else
		ptr = base_x;

	tmp = malloc(sizeof(*tmp) * i + 1);

	while (num)
	{
		tmp[i++] = ptr[num % base];
		tmp = _realloc(tmp, i, i + 1);
		num = num / base;
	}
	tmp[i] = '\0';
	rev_string(tmp);

	return (tmp);
}
