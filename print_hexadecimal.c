#include "main.h"
/**
 * print_hexadecimal - function that hexadecimal notation
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags: flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	return (print_hexa(argument, "0123456789abcdef", buff,
		flags, 'x', width, pec, size));
}
