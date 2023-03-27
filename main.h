#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>


typedef struct types
{
	char *t;
	int (*f)(va_list);
} type_t;

int _printf(const char *format, ...);
int (*get_checker(char))(va_list);
int input_char(va_list args);
int input_str(va_list args);
int input_cent(va_list args);
int input_int(va_list args);

#endif

