#include "main.h"
/**
 * print_str - function that print string
 * @argument: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  flags
 * @width: width.
 * @pec: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_str(va_list argument, char buff[],
	int flags, int width, int pec, int size)
{
	int wen = 0, j;
	char *str = va_arg(argument, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(pec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (pec >= 6)
			str = "      ";
	}

	while (str[wen] != '\0')
		wen++;

	if (pec >= 0 && pec < wen)
		wen = pec;

	if (width > wen)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], wen);
			for (j = width - wen; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - wen; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], wen);
			return (width);
		}
	}

	return (write(1, str, wen));
}
