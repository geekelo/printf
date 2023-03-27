#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Author: Chidiadi E. Nwosu
 * Desc: file containing function prototypes for printf project
 */
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>


/********************* my_printf.c *****************/
/**
 * struct op - Struct op
 *
 * @specifier: The format specifier
 * @f: The function associated
 */
typedef struct op
{
	char specifier;
	int (*f)(va_list);
} handler;

int _printf(const char *format, ...);
int (*format_handler(char s))(va_list);



/*************** stdout_helphers.c ***************/
int _putchar(char);
int _print_char(va_list);
int _print_string(va_list);
int _print_percent(va_list);
int _print_decimal(va_list);



/*************** stdout_helphers.c ***************/
int _print_binary(va_list);



/*************** helper_functions1.c **************/
char *_itoa(int num);
int _atoi(char *s);
int _strlen(char *s);
void rev_string(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);



/*************** helper_functions2.c **************/
char *_memcpy(char *dest, char *src, unsigned int n);
int convert_to_10(int num, int base);
char *convert_to_base(unsigned int num, unsigned int base);
int non_printable(char *str);
char *rot13(char *str);



#endif
