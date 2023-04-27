#include "main.h"
/**
 * hold_view_char - function that prints a string
 * @c: char.
 * @buff: array to print
 * @flags:  flags.
 * @width: width.
 * @precision: precision
 * @size: Size
 * Return: Number of chars printed.
 */
int hold_view_char(char c, char buff[],
		int flags, int width, int precision, int size)
{
	int j = 0;
	char ad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		ad = '0';

	buff[j++] = c;
	buff[j] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
	for (j = 0; j < width - 1; j++)
		buff[BUFF_SIZE - j - 2] = ad;

	if (flags & F_MINUS)
		return (write(1, &buff[0], 1) +
				write(1, &buff[BUFF_SIZE - j - 1], width - 1));
	else
		return (write(1, &buff[BUFF_SIZE - j - 1], width - 1) +
				write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/************** view numbers ************/

/**
 * view_numb - function prints a string
 * @is_neg: arguments
 * @nd: char.
 * @buff: array
 * @flags:  flags
 * @width: width.
 * @precision: precision
 * @size: Size
 * Return: Number of chars printed.
 */
int view_numb(int is_neg, int nd, char buff[],
		int flags, int width, int precision, int size)
{
	int wen = BUFF_SIZE - nd - 1;
	char ad = ' ', xt_h = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		ad = '0';
	if (is_neg)
		xt_h = '-';
	else if (flags & F_PLUS)
		xt_h = '+';
	else if (flags & F_SPACE)
		xt_h = ' ';
	return (view_num(nd, buff, flags, width, precision, wen, ad, xt_h));
}


/**
 * view_num - Writing number using a bufffer
 * @nd: point number starts on the buffer
 * @buff: Buffer
 * @flags: Flags
 * @width: width
 * @pec: Precision
 * @wen: length
 * @ad: char padding
 * @xt_c: char
 * Return: printed chars.
 */
int view_num(int nd, char buff[], int flags,
		int width, int pec, int wen, char ad, char xt_c)
{
	int j, ad_start = 1;

	if (pec == 0 && nd == BUFF_SIZE - 2 && buff[nd] == '0' && width == 0)
		return (0);
	if (pec == 0 && nd == BUFF_SIZE - 2 && buff[nd] == '0')
		buff[nd] = ad = ' '; /* width is displayed with padding ' ' */
	if (pec > 0 && pec < wen)
		ad = ' ';
	while (pec > wen)
		buff[--nd] = '0', wen++;
	if (xt_c != 0)
		wen++;
	if (width > wen)
	{
		for (j = 1; j < width - wen + 1; j++)
			buff[j] = ad;
		buff[j] = '\0';
		if (flags & F_MINUS && ad == ' ')/* Asign extra char to left of buffer */
		{
		if (xt_c)
			buff[--nd] = xt_c;
		return (write(1, &buff[nd], wen) + write(1, &buff[1], j - 1));
		}
		else if (!(flags & F_MINUS) && ad == ' ')/* extra char to left of buff */
		{
			if (xt_c)
				buff[--nd] = xt_c;
			return (write(1, &buff[1], j - 1) + write(1, &buff[nd], wen));
		}
		else if (!(flags & F_MINUS) && ad == '0')/* extra char to left of padd */
		{
			if (xt_c)
				buff[--ad_start] = xt_c;
			return (write(1, &buff[ad_start], j - ad_start) +
					write(1, &buff[nd], wen - (1 - ad_start)));
		}
	}
	if (xt_c)
		buff[--nd] = xt_c;
	return (write(1, &buff[nd], wen));
}


/**
 * view_unsgnd - function that writes an unsigned number
 * @is_neg: negative number indication
 * @j: starting point
 * @buff: Array of chars
 * @flags: Flags
 * @width: Width
 * @pec: Precision
 * @size: Size specifier
 *
 * Return: chars.
 */
int view_unsgnd(int is_neg, int j,
	char buff[],
	int flags, int width, int pec, int size)
{
	int wen = BUFF_SIZE - j - 1, k = 0;
	char ad = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (pec == 0 && j == BUFF_SIZE - 2 && buff[j] == '0')
		return (0);

	if (pec > 0 && pec < wen)
		ad = ' ';

	while (pec > wen)
	{
		buff[--j] = '0';
		wen++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		ad = '0';

	if (width > wen)
	{
		for (k = 0; k < width - wen; k++)
			buff[k] = ad;

		buff[k] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buff[j], wen) + write(1, &buff[0], k));
		}
		{
			return (write(1, &buff[0], k) + write(1, &buff[j], wen));
		}
	}

	return (write(1, &buff[j], wen));
}

/**
 * write_pointer - function write a memory address
 * @buff: buffer arrays of chars
 * @j: start point
 * @wen: length
 * @width: Width
 * @flags: Flags
 * @ad: padding
 * @xt_c: extra char
 * @ad_start: padding start point
 *
 * Return: Number of written chars.
 */
int write_pointer(char buff[], int j, int wen,
	int width, int flags, char ad, char xt_c, int ad_start)
{
	int k;

	if (width > wen)
	{
		for (k = 3; k < width - wen + 3; k++)
			buff[k] = ad;
		buff[k] = '\0';
		if (flags & F_MINUS && ad == ' ')
		{
			buff[--j] = 'x';
			buff[--j] = '0';
			if (xt_c)
				buff[--j] = xt_c;
			return (write(1, &buff[j], wen) + write(1, &buff[3], k - 3));
		}
		else if (!(flags & F_MINUS) && ad == ' ')
		{
			buff[--j] = 'x';
			buff[--j] = '0';
			if (xt_c)
				buff[--j] = xt_c;
			return (write(1, &buff[3], k - 3) + write(1, &buff[j], wen));
		}
		else if (!(flags & F_MINUS) && ad == '0')
		{
			if (xt_c)
				buff[--ad_start] = xt_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[ad_start], k - ad_start) +
				write(1, &buff[j], wen - (1 - ad_start) - 2));
		}
	}
	buff[--j] = 'x';
	buff[--j] = '0';
	if (xt_c)
		buff[--j] = xt_c;
	return (write(1, &buff[j], BUFF_SIZE - j - 1));
}
