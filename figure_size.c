#include "main.h"
/**
 * figure_size - a function that calculates the size to run the argument
 * @format: string  to print the arguments.
 * @k: List of arguments to be printed.
 * Return: size.
 */
int figure_size(const char *format, int *k)
{
	int cal = *k + 1;
	int size = 0;

	if (format[cal] == 'l')
		size = S_LONG;
	else if (format[cal] == 'h')
		size = S_SHORT;

	if (size == 0)
		*k = cal - 1;
	else
		*k = cal;

	return (size);
}
