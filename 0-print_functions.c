#include "main.h"

/**
 * returnChar - prints character
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int returnChar(va_list args, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * returnInt - prints integer
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int returnInt(va_list args, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(args, long);
	else if (params->h_modifier)
		l = (short int)va_arg(args, int);
	else
		l = (int)va_arg(args, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * returnStr - prints string
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int returnStr(va_list args, params_t *params)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * returnPercent - prints string
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int returnPercent(va_list args, params_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}

/**
 * sFunction - custom format specifier
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int sFunction(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
