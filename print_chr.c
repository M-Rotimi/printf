#include "main.h"

/**
 * print_char - function that prints a char
 * @argument: arguments
 * @buff: Buffer array to handle print
 * @flags: flags
 * @width: Width
 * @pec: Precision
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list argument, char buff[],
		int flags, int width, int pec, int size)
{
	char c = va_arg(argument, int);

	return (hold_view_char(c, buff, flags, width, pec, size));
}
