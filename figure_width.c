#include "main.h"
/**
 * figure_width - function that calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @k: List of arguments to be printed.
 * @ls: list of arguments.
 * Return: width.
 */
int figure_width(const char *format, int *k, va_list ls)
{
	int cal;
	int width = 0;

	for (cal = *k + 1; format[cal] != '\0'; cal++)
	{
		if (is_digit(format[cal]))
		{
			width *= 10;
			width += format[cal] - '0';
		}
		else if (format[cal] == '*')
		{
			cal++;
			width = va_arg(ls, int);
			break;
		}
		else
			break;
	}

	*k = cal - 1;

	return (width);
}
