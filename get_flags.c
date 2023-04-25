#include "main.h"

/**
 * get_bilal3 - Calculates active bilal3
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_bilal3(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int bilal1, bilal2;
	int bilal3 = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (bilal2 = *i + 1; format[bilal2] != '\0'; bilal2++)
	{
		for (bilal1 = 0; FLAGS_CH[bilal1] != '\0'; bilal1++)
			if (format[bilal2] == FLAGS_CH[bilal1])
			{
				bilal3 |= FLAGS_ARR[bilal1];
				break;
			}

		if (FLAGS_CH[bilal1] == 0)
			break;
	}

	*i = bilal2 - 1;

	return (bilal3);
}
