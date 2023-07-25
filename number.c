#include "main.h"

/**
 * convertNum - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convertNum(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * printUnsigned - prints unsigned integer numbers
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int printUnsigned(va_list args, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	params->unsign = 1;
	return (print_number(convertNum(l, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * printAddress - prints address
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int printAddress(va_list args, params_t *params)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convertNum(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
