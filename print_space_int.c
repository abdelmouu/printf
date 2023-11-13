#include "holberton.h"
/**
 * prinsint - prints an integer, preceded by a space.
 * @arguments: The integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinsint(va_list arguments, char *buf, unsigned int ibuf)
{
	int input_in;
	unsigned int in, temp, i, div;

	input_in = va_arg(arguments, int);
	if (input_in < 0)
	{
		in = input_in * -1;
		ibuf = handl_buf(buf, '-', ibuf);
	}
	else
	{
		in = input_in;
		ibuf = handl_buf(buf, ' ', ibuf);
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
