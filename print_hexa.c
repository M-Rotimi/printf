#include "main.h"
/**
 * print_hexa - function that prints a hexadecimal in lower or upper
 * @argument: List of arguments
 * @run_to: Array
 * @buff: Buffer array
 * @flags: flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa(va_list argument, char run_to[], char buff[],
	int flags, char flag_ch, int width, int pec, int size)
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
		buff[j--] = run_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buff[j--] = flag_ch;
		buff[j--] = '0';
	}

	j++;

	return (view_unsgnd(0, j, buff, flags, width, pec, size));
}
