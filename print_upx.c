#include "main.h"
/**
 * print_upx - prints a decimal in uppercase hexadecimal format.
 * @arguments: The decimal value to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed.
 */
int print_upx(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isnega, c, frst_dig;
	char *hexa, *bin;

	int_input = va_arg(arguments, int);
	isnega = 0;
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnega = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_bin_array(bin, int_input, isnega, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = fill_hex_array(bin, hexa, 1, 8);
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
