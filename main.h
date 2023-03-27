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

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char specifier;
	int (*f)(va_list);
} handler;

int _printf(const char *format, ...);
int _putchar(char);
int _print_char(va_list);
int _print_string(va_list);
int _print_percent(va_list);
int (*format_handler(char s))(va_list);


#endif
