#include "main.h"

/**
 * figure_flags - Calculates active flags
 * @format: Formatted string
 * @*k: take a parameter.
 * Return: Flags:
 */
int figure_flags(const char *format, int *k)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  1 */
	int j, cal;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cal = *k + 1; format[cal] != '\0'; cal++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cal] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*k = cal - 1;

	return (flags);
}
