#include "main.h"
/**
 * print_usr - prints a string and counts the number of chrs non countable.
 * @arguments: the input string.
 * @buf: the buffer pointer.
 * @ibuf: the index for the buffer pointer.
 *
 * Return: the number of characters that are not printable.
 */
int print_usr(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hexa, *bin;
	unsigned int i, j, sum;

	str = va_arg(arguments, unsigned char *);
	bin = malloc(sizeof(char) * (32 + 1));
	hexa = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = handl_buf(buf, '\\', ibuf);
			ibuf = handl_buf(buf, 'x', ibuf);
			j = str[i];
			bin = fill_bin_array(bin, j, 0, 32);
			hexa = fill_hex_array(bin, hexa, 1, 8);
			ibuf = handl_buf(buf, hexa[6], ibuf);
			ibuf = handl_buf(buf, hexa[7], ibuf);
			sum += 3;
		}
		else
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	free(bin);
	free(hexa);
	return (i + sum);
}
