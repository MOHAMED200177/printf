#include "main.h"
#include <string.h>
/**
 * print_char - function to print char
 * @a: char to print
 * @count: number of printed letters
 * Return: number of printed letters after function
 */
int print_char(char a, int count)
{
	_putchar(a);
	count++;
	return (count);
}

/**
 * print_string - function to print string
 * @a: pointer to string
 * @count: number of printed letters
 * Return: number of printed letters after function
 */
int print_string(char *a, int count)
{
	int i = 0;

	if (!a)
	{
		exit(1);
	}
	else
	{
		while (a[i] != '\0')
		{
			_putchar(a[i]);
			i++;
			count++;
		}
	}
	return (count);
}

