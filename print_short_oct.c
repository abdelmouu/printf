#include "main.h"
/**
 * prinhoct - prints a long unsigned integer in octal format.
 * @arguments: The unsigned integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinhoct(va_list arguments, char *buf, unsigned int ibuf)
{
	short int input, i, isnega, c, frst_dig;
	char *octl, *bin;

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
	bin = fill_binary_array(bin, input, isnega, 16);
	octl = malloc(sizeof(char) * (6 + 1));
	octl = fill_short_oct_array(bin, octl);
	for (frst_dig = i = c = 0; octl[i]; i++)
	{
		if (octl[i] != '0' && frst_dig == 0)
			frst_dig = 1;
		if (frst_dig)
		{
			ibuf = handl_buf(buf, octl[i], ibuf);
			c++;
		}
	}
	free(bin);
	free(octl);
	return (c);
}
