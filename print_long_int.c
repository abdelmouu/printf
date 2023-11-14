#include "main.h"

/**
 * prinlint - Prints a long integer value.
 *
 * This function writes the x long integer value to the specified buffer.
 *
 * @arguments: Input long integer value to be printed.
 * @buf: Buffer pointer to store the long integer value.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: The number of characters printed for the long integer value.
 */

int prinlint(va_list arguments, char *buf, unsigned int ibuf)
{
	long int x;
	unsigned long int i, in, tmp, div, neg;

	x = va_arg(arguments, long int);
	neg = 0;
	if (x < 0)
	{
		in = x * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		neg = 1;
	}
	else
	{
		in = x;
	}

	tmp = in;
	div = 1;
	while (tmp > 9)
	{
		div *= 10;
		tmp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((in / div) % 10) + '0', ibuf);
	}
	return (i + neg);
}
