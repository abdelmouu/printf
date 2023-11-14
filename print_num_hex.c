#include "main.h"
/**
 * prinnhex - prints an unsigned integer in hexa format, prefixing zero.
 * @arguments: The unsigned integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinnhex(va_list arguments, char *buf, unsigned int ibuf)
{
	int input, i, isnega, c, frst_dig;
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
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_bin_array(bin, input, isnega, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = fill_hex_array(bin, hexa, 0, 8);
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
	return (c + 2);
}
