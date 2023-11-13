#include "main.h"

/**
 * print_rev - prints the input strging in reverse order.
 * @arguments: The input strging to reverse.
 * @buf: The buffer pointer where the reversed strging will be written.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed to the buffer.
 */
int print_rev(va_list arguments, char *buf, unsigned int ibuf)
{
	char *strg;
	unsigned int i;
	int j = 0;
	char nil[] = "(llun)";

	strg = va_arg(arguments, char *);
	if (strg == NULL)
	{
		for (i = 0; nil[i]; i++)
			ibuf = handl_buf(buf, nil[i], ibuf);
		return (6);
	}
	for (i = 0; strg[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		ibuf = handl_buf(buf, strg[j], ibuf);
	}
	return (i);
}
