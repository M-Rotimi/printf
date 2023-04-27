#include "main.h"
/**
 * print_reverse - function that prints reverse string.
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags: flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Numbers of chars printed
 */

int print_reverse(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(argument, char *);

	if (str == NULL)
	{
		UNUSED(pec);

		str = ")Null(";
	}
	for (j = 0; str[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char z = str[j];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
