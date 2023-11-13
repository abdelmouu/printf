#include "holberton.h"
/**
 * prinhint - prints a short integer in decimal format.
 * @arguments: The short integer to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int prinhint(va_list arguments, char *buf, unsigned int ibuf)
{
	short int input;
	unsigned short int in, temp, i, div, isng;

	input = va_arg(arguments, int);
	isng = 0;
	if (input < 0)
	{
		in = input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isng = 1;
	}
	else
	{
		in = input;
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
	return (i + isng);
}
