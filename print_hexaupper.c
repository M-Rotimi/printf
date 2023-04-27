#include "main.h"
/**
 * print_hexa_upper - function that prints in upper hexadecimal notation
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags: flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	return (print_hexa(argument, "0123456789ABCDEF", buff,
		flags, 'X', width, pec, size));
}
