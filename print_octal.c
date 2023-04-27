#include "main.h"
/**
 * print_octal - function that prints in octal notation
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags:  flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_octal(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(argument, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = change_size_unsgnd(num, size);

	if (num == 0)
		buff[j--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[j--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buff[j--] = '0';

	j++;

	return (view_unsgnd(0, j, buff, flags, width, pec, size));
}
