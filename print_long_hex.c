#include "main.h"

/**
 * prinlhex - Prints a long decimal as a hexadecimal value.
 *
 * This function converts the input long decimal number
 * to its hexadecimal format
 * and writes it to the specified buffer.
 *
 * @arguments: Input long decimal number to be converted.
 * @buf: Buffer pointer to store the hexadecimal representation.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: The number of characters printed for the hexadecimal representation.
 */
int prinlhex(va_list arguments, char *buf, unsigned int ibuf)
{
	long int i, in, neg, c, indexPr;
	char *hex, *bin;

	in = va_arg(arguments, long int);
	neg = 0;
	if (in == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (in < 0)
	{
		in = (in * -1) - 1;
		neg = 1;
	}

	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_bin_array(bin, in, neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex_array(bin, hex, 0, 16);
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
