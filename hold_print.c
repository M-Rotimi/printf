#include "main.h"
/**
 * handle_print - function that prints an argument
 * @fmt: Formatted string
 * @ls: arguments list.
 * @nd: parameter
 * @buff: array to be print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2 always.
 */
int handle_print(const char *fmt, int *nd, va_list ls, char buff[],
		int flags, int width, int precision, int size)
{
	int j, unknow_wen = 0, release_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'j', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
	if (fmt[*nd] == fmt_types[j].fmt)
		return (fmt_types[j].fn(ls, buff, flags, width, precision, size));

	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*nd] == '\0')
			return (-1);
		unknow_wen += write(1, "%%", 1);
		if (fmt[*nd - 1] == ' ')
			unknow_wen += write(1, " ", 1);
		else if (width)
		{
			--(*nd);
			while (fmt[*nd] != ' ' && fmt[*nd] != '%')
				--(*nd);
			if (fmt[*nd] == ' ')
				--(*nd);
			return (1);
		}
		unknow_wen += write(1, &fmt[*nd], 1);
		return (unknow_wen);
	}
	return (release_chars);
}
