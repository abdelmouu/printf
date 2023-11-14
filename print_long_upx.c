#include "main.h"
/**
 * prinlupx - prints a long unsigned integer in hexadecimal format.
 * @arguments: The unsigned integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinlupx(va_list arguments, char *buf, unsigned int ibuf)
{
	long int input, i, isnega, c, frst_dig;
	char *hexa, *bin;

	input = va_arg(arguments, long int);
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

	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_binary_array(bin, input, isnega, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = fill_hex_array(bin, hexa, 1, 16);
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
