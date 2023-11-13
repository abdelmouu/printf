#include "main.h"
/**
 * prinhhex - prints a short unsigned integer in hexadecimal format.
 * @arguments: The unsigned integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinhhex(va_list arguments, char *buf, unsigned int ibuf)
{
	short int input, i, isnega, c, frst_dig;
	char *hexa, *bin;

	input = va_arg(arguments, int);
	isnega = 0;
	if (input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		isnega = 1;
	}

	bin = malloc(sizeof(char) * (16 + 1));
	bin = fill_bin_array(bin, input, isnega, 16);
	hexa = malloc(sizeof(char) * (4 + 1));
	hexa = fill_hex_array(bin, hexa, 0, 4);
	for (frst_dig = i = c = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && frst_dig == 0)
			frst_dig = 1;
		if (frst_dig)
		{
			ibuf = handl_buf(buf, hexa[i], ibuf);
			c++;
		}
	}
	free(bin);
	free(hexa);
	return (c);
}
