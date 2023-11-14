#include "main.h"
/**
 * prinpint - prints an integer with a leading plus sign.
 * @arguments: The integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinpint(va_list arguments, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int in, temp, i, div;

	input = va_arg(arguments, int);
	if (input < 0)
	{
		in = input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
	}
	else
	{
		in = input;
		ibuf = handl_buf(buf, '+', ibuf);
	}
	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}
