#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Author: Chidiadi E. Nwosu
 * Desc: file containing function prototypes for printf project
 */
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char);
int _puts(char *);
int format_handler(va_list ptr, char s);
char *base_converter(int input, int base);
char *_itoa(int num);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
void rev_string(char *s);
int print_number(int num);

#endif
