#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	int y;

	char p = 'f';
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
 	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	y = _printf("%c\n", p);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}

