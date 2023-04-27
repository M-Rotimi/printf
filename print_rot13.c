#include "main.h"
/**
 * print_rot13string - function that print a string in rot13.
 * @argument: List of arguments
 * @buff: Buffer array
 * @flags: flags
 * @width: width
 * @pec: Precision
 * @size: Size
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list argument, char buff[],
		int flags, int width, int pec, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(argument, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(pec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;

			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
