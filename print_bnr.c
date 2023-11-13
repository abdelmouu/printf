#include "main.h"

/**
 * print_bnr - Prints a decimal number in bin.
 *
 * This function converts an input decimal number
 * to its bin representation and writes it to the specified buffer.
 *
 * @arguments: Input decimal number.
 * @buf: Buffer pointer to store the bin representation.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int print_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
	int i, c, input, indexPr, neg;
	char *bin;

	input = va_arg(arguments, int);
	neg = 0;
	if (input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_bin_array(bin, input, neg, 32);
	indexPr = 0;
	for (c = i = 0; bin[i]; i++)
	{
		if (indexPr == 0 && bin[i] == '1')
			indexPr = 1;
		if (indexPr == 1)
		{
			ibuf = handl_buf(buf, bin[i], ibuf);
			c++;
		}
	}
	free(bin);
	return (c);
}
