#include "main.h"
/**
 * print_non_printable -function that print ascii hexa of non printable chars
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags: flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_non_printable(va_list argument, char buff[],
		int flags, int width, int pec, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(argument, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(pec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j]))
			buff[j + offset] = str[j];
		else
			offset += add_hexa_code(str[j], buff, j + offset);
		j++;
	}
	buff[j + offset] = '\0';
	return (write(1, buff, j + offset));
}
