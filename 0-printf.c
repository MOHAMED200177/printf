#include "main.h"
/**
 * _printf - function to print any datatype
 *
 * @format: pointer to the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i = 0; /*indicator*/
	int count = 0;/*counter*/
	/*intial check*/
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	/*list arguments*/
	va_list args;

	va_start(args, format);
	for (i = 0; i < strlen(format); i++)
	{
		while (format[i] && format[i] != '%')
		{
			putchar(format[i]);
			i++;
			count++;
		}
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count = print_char((va_arg(args, int)), count);
					break;
				case 's':
					count = print_string((va_arg(args, char*)), count);
					break;
				case 'i':
				case 'd':
					count = print_int((va_arg(args, int)), count);
					break;
			}
		}
	}
	va_end(args);
	return (count);

}

