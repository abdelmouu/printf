#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_hex - Converts a decimal number to its hex representation.
 *
 * This function converts the input decimal number to its hex format
 * and writes it to the specified buffer.
 *
 * @arguments: Input decimal number to be converted.
 * @buf: Buffer pointer to store the hex representation.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: The number of characters printed in the hex representation.
 */

int print_hex(va_list arguments, char *buf, unsigned int ibuf)
{
	int input, i, neg, c, indexPr;
	char *hex, *bin;

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
	bin = fill_binary_array(bin, input, neg, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = fill_hex_array(bin, hex, 0, 8);
	for (indexPr = i = c = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && indexPr == 0)
			indexPr = 1;
		if (indexPr)
		{
			ibuf = handl_buf(buf, hex[i], ibuf);
			c++;
		}
	}
	free(bin);
	free(hex);
	return (c);
}
