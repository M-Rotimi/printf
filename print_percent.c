#include "main.h"
/**
 * print_percent - function that prints a percent sign
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags:  flags
 * @width: width.
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_percent(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	UNUSED(argument);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(pec);
	UNUSED(size);
	return (write(1, "%%", 1));
}
