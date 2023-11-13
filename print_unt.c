#include "main.h"
/**
 * print_unt - prints an unsigned integer in decimal format.
 * @arguments: The unsigned integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int print_unt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int in, temp, i, div;

	in = va_arg(arguments, unsigned int);
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
	return (i);
}
