#include "main.h"


/**
 * formatchecker -
 *
 *
 */


int (*get_checker(char format))(va_list)
{
	int count;

	type_t specifiers[] = {
		{"c", input_char},
		{"s", input_str},
		{"%", input_cent},
		{"d", input_int}
	};
	
	for (count = 0; count < 4; count++)
	{
		if (format == *(specifiers[count].t))
		{
			return (specifiers[count].f);
		}
	}


}

int input_char(va_list args)
{
	char x = va_arg(args, int);
	int v = write(1, &x, 1);
	return (v);

}


int input_str(va_list args)
{
	int v, count;

	char *x = va_arg(args, char *);
	
	for (count = 0; x[count] != '\0'; count++)
	{
	 v = write(1, &x[count], 1);
	}
	return (v);
}


int input_cent(va_list args)
{
	char x = va_arg(args, int);
	int v = write(1, "%", 1);
	return (v);

}

int input_int(va_list args)
{	

	int x;
	char arr[1];
	x = va_arg(args, int);
	int v = 0;
	int container = x;
	int container2 = x;
	int pow = 1;

	
	while (container > 9)
	{
	 	pow *= 10;
		container = container / 10;
	}

	while (pow > 1)
	{
		arr[0] = ((container2 / 10)) + '0';
		v += write(1, arr, 1);
		container *= 10;
		pow = pow / 10;
	}
	arr[0] = (container2 % 10) + '0'; 
	v += write(1, arr, 1);
	return (v);

}

