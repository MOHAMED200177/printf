
/**
 * print_char - function to print char
 * @a: char to print
 * @count: number of printed letters
 * Return: number of printed letters after function
 */
int print_char(char a, int count)
{
	putchar(a);
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
			putchar(a[i]);
			i++;
			count++;
		}
	}
	return (count);
}

/**
 * print_int - function to print int
 * @num: int to print
 * @count: number of printed letters
 * Return: number of printed letters after function
 */
int print_int(int num, int count)
{
	int len = 0;
	int temp = num;

	while (temp / 10)
	{
		len++;
		temp = temp / 10;
	}

	while (num / 10)
	{
		temp = num / (power(10, len));
		putchar(temp + '0');
		num = num % (power(10, len));
		count++;
		len--;
	}
	/*print last digit*/
	putchar (num + '0');
	count++;
	return (count);
}


/**
 * power - function to get the power of number
 * @base: number to get its power
 * @pow: power
 * Return: power of number
 */

int power(int base, int pow)
{
	int num = 1;

	if (pow != 0)
	{
		while (pow)
		{
			num *= base;
			pow--;
		}
	}
	else if (pow < 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
	return (num);
}
