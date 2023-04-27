#include "main.h"
/**
 * print_binary - function that prints an unsigned numb
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags:  flags
 * @width: width.
 * @pec: Precision
 * @size: Size
 * Return: Numbers of char printed.
 */
int print_binary(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	unsigned int j, k, l, sum;
	unsigned int b[32];
	int count;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(pec);
	UNUSED(size);

	j = va_arg(argument, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	b[0] = j / k;
	for (l = 1; l < 32; l++)
	{
		k /= 2;
		b[l] = (j / k) % 2;
	}
	for (l = 0, sum = 0, count = 0; l < 32; l++)
	{
		sum += b[l];
		if (sum || l == 31)
		{
			char z = '0' + b[l];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
