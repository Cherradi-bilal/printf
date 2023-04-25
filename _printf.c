#include "main.h"

void print_buffer(char buffer[], int *bilal5);

/**
 * _printf - Printf function
 * @bilal : bilal .
 * Return: Printed chars.
 */
int _printf(const char *bilal , ...)
{
	int i, bilal3 = 0, bilal1 = 0;
	int bilal4, width, precision, size, bilal5 = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (bilal  == NULL)
		return (-1);

	va_start(list, bilal );

	for (i = 0; bilal  && bilal [i] != '\0'; i++)
	{
		if (bilal [i] != '%')
		{
			buffer[bilal5++] = bilal [i];
			if (bilal5 == BUFF_SIZE)
				print_buffer(buffer, &bilal5);
			/* write(1, &bilal [i], 1);*/
			bilal1++;
		}
		else
		{
			print_buffer(buffer, &bilal5);
			bilal4 = get_bilal4(bilal , &i);
			width = get_width(bilal , &i, list);
			precision = get_precision(bilal , &i, list);
			size = get_size(bilal , &i);
			++i;
			bilal3 = handle_print(bilal , &i, list, buffer,
				bilal4, width, precision, size);
			if (bilal3 == -1)
				return (-1);
			bilal1 += bilal3;
		}
	}

	print_buffer(buffer, &bilal5);

	va_end(list);

	return (bilal1);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @bilal5: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bilal5)
{
	if (*bilal5 > 0)
		write(1, &buffer[0], *bilal5);

	*bilal5 = 0;
}
