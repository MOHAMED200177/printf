#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (printFlag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = printWidth(p, &params, args);
		p = printPrecision(p, &params, args);
		if (printModifire(p, &params))
			p++;
		if (!printSpecifier(p))
			sum += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += returnFromTo(p, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (sum);
}
