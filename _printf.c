#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, release = 0, release_chars = 0;
	int flags, width, precision, size, buff_n = 0;

	va_list ls;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ls, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buff[buff_n++] = format[j];
		if (buff_n == BUFF_SIZE)
			print_buf(buff, &buff_n);
		release_chars++;
		}
		else
		{
			print_buf(buff, &buff_n);
			flags = figure_flags(format, &j);
			width = figure_width(format, &j, ls);
			precision = figure_precision(format, &j, ls);
			size = figure_size(format, &j);
			++j;
			release = handle_print(format, &j, ls, buff,
					flags, width, precision, size);
			if (release == -1)
				return (-1);
			release_chars += release;
		}
	}
	print_buf(buff, &buff_n);

	va_end(ls);

	return (release_chars);
}

/**
 * print_buf - function that prints contents of the buffer if it exist
 * @buff: chars
 * @buff_n: chars to add and length
 */
void print_buf(char buff[], int *buff_n)
{
	if (*buff_n > 0)
		write(1, &buff[0], *buff_n);

	*buff_n = 0;
}
