#include "main.h"
/**
 * print_int - Print int
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags: flags
 * @width: width.
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_int(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	int j = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(argument, long int);
	unsigned long int num;

	n = change_size_value(n, size);

	if (n == 0)
		buff[j--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buff[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (view_numb(is_neg, j, buff, flags, width, pec, size));
}
