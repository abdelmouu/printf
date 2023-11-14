#include "main.h"
/**
 * prinloct - prints a long unsigned integer in octal format.
 * @arguments: The long unsigned integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinloct(va_list arguments, char *buf, unsigned int ibuf)
{
	long int input, i, isnega, c, frst_dig;
	char *oct, *bin;

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
	bin = fill_bin_array(bin, input, isnega, 64);
	oct = malloc(sizeof(char) * (22 + 1));
	oct = fill_long_oct_array(bin, oct);
	for (frst_dig = i = c = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && frst_dig == 0)
			frst_dig = 1;
		if (frst_dig)
		{
			ibuf = handl_buf(buf, oct[i], ibuf);
			c++;
		}
	}
	free(bin);
	free(oct);
	return (c);
}
