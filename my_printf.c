#include "main.h"

/**
 * _printf - prints inputs and data assigned to variables
 * @format: the formats specifiers to variables 
 * that the fucntion can recognize and print
 * Return: the total number of characters printed on sucess
 */

int _printf(const char *format, ...)
{
	int index, returned_value, value = 0;
	va_list args;
	int (*f)(va_list);

	va_start(args, format);
	if (format)
	{
		for (index = 0; index < strlen(format); index++)
		{
			if (format[index] != '%')
				value +=  write(1, &format[index], 1);
			if (format[index] == '%' && format[index + 1] != '\0')
			{
				f = get_checker(format[index + 1]);
				if (f)
				{
					returned_value = f(args);
					value += returned_value;
				}
				index++;
			}
		}
	}
	return (value);
}

