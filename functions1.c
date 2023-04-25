#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @bilal2: Buffer array to handle print
 * @bilal3:  Calculates active bilal3
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(bilal1, char bilal2[],
	int bilal3, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bilal2[i--] = '0';

	bilal2[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bilal2[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, bilal2, bilal3, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @bilal2: Buffer array to handle print
 * @bilal3:  Calculates active bilal3
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(bilal1, char bilal2[],
	int bilal3, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bilal2[i--] = '0';

	bilal2[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bilal2[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (bilal3 & F_HASH && init_num != 0)
		bilal2[i--] = '0';

	i++;

	return (write_unsgnd(0, i, bilal2, bilal3, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @bilal2: Buffer array to handle print
 * @bilal3:  Calculates active bilal3
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(bilal1, char bilal2[],
	int bilal3, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", bilal2,
		bilal3, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @bilal2: Buffer array to handle print
 * @bilal3:  Calculates active bilal3
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(bilal1, char bilal2[],
	int bilal3, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", bilal2,
		bilal3, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @bilal2: Buffer array to handle print
 * @bilal3:  Calculates active bilal3
 * @flag_ch: Calculates active bilal3
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(bilal1, char map_to[], char bilal2[],
	int bilal3, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bilal2[i--] = '0';

	bilal2[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bilal2[i--] = map_to[num % 16];
		num /= 16;
	}

	if (bilal3 & F_HASH && init_num != 0)
	{
		bilal2[i--] = flag_ch;
		bilal2[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, bilal2, bilal3, width, precision, size));
}
