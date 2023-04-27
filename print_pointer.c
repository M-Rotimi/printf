#include "main.h"
/**
 * print_pointer - function that print a pointer variable
 * @argument: List of arguments
 * @buff: Buffer array to handle print
 * @flags: flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed.
 */
int print_pointer(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	char xt_c = 0, ad = ' ';
	int nd = BUFF_SIZE - 2, wen = 2, ad_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char run_to[] = "0123456789abcdef";
	void *addrs = va_arg(argument, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(pec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[nd--] = run_to[num_addrs % 16];
		num_addrs /= 16;
		wen++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		ad = '0';
	if (flags & F_PLUS)
		xt_c = '+', wen++;
	else if (flags & F_SPACE)
		xt_c = ' ', wen++;

	nd++;

	return (write_pointer(buff, nd, wen,
		width, flags, ad, xt_c, ad_start));
}
