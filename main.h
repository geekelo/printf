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
#define ABS(x) (((x) < 0) ? (-x) : (x))


int _printf(const char *format, ...);
int print_address(void *address);
int _putchar(char);
int _puts(char *, int);
int format_handler(va_list ptr, char s);
char *_itoa(int num);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
void rev_string(char *s);
int print_number(int num);
char *convert_to_base(unsigned int num, unsigned int base);
int convert_to_10(int num, int base);
char *_memcpy(char *dest, char *src, unsigned int n);
int _print_strings(char *c);
int non_printable(char *str);
char *rot13(char *str);

#endif
