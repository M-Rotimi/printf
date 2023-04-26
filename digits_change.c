#include "main.h"

/**
 * is_printable - function that evaluates a char
 * @c: Char
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hexa_code - function that adds hexadecimal code to buffer
 * @buff: buffer array of chars.
 * @i: start point to add.
 * @ascii_value: ASSCI value.
 * Return: Always 3
 */
int add_hexa_code(char ascii_value, char buff[], int j)
{
	char run_to[] = "0123456789ABCDEF";

	if (ascii_value < 0)
		ascii_value *= -1;

	buff[j++] = '\\';
	buff[j++] = 'x';

	buff[j++] = run_to[ascii_value / 16];
	buff[j] = run_to[ascii_value % 16];

	return (3);
}

/**
 * is_digit - function that indicate a digit
 * @c: Char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * change_size_value - function that changes number to a particular a size
 * @numb: Number.
 * @size: type indication.
 *
 * Return: Casted value of num
 */
long int change_size_value(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * change_size_unsgnd - function that changes number to a particular a size
 * @numb: Number
 * @size: type indication
 *
 * Return: Casted value of num
 */
long int change_size_unsgnd(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
