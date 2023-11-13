#include "main.h"
/**
 * print_add - Prints the press of an input variable.
 *
 * This function prints the press of the input variable
 * to the specified buffer.
 *
 * @arguments: Input press.
 * @buf: Buffer pointer to store the output.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */

int print_add(va_list arguments, char *buf, unsigned int ibuf)
{
	void *p;
	long int input;
	int i, c, digitPr, isneg;
	char *hex, *bin;
	char nill[] = "(nil)";

	p = (va_arg(arguments, void *));
	if (p == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (5);
	}
	input = (intptr_t)p;
	isneg = 0;
	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_bin_array(bin, input, isneg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex_array(bin, hex, 0, 16);
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);
	for (digitPr = i = c = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && digitPr == 0)
			digitPr = 1;
		if (digitPr)
		{
			ibuf = handl_buf(buf, hex[i], ibuf);
			c++;
		}
	}
	free(bin);
	free(hex);
	return (c + 2);
}
