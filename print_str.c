#include "main.h"
/**
 * print_strg - writes the given string to standard output.
 * @arguments: The input string to print.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: 1 on success.
 */
int print_strg(va_list arguments, char *buf, unsigned int ibuf)
{
	char *strg;
	unsigned int i;
	char nil[] = "(null)";

	strg = va_arg(arguments, char *);
	if (strg == NULL)
	{
		for (i = 0; nil[i]; i++)
			ibuf = handl_buf(buf, nil[i], ibuf);
		return (6);
	}
	for (i = 0; strg[i]; i++)
		ibuf = handl_buf(buf, strg[i], ibuf);
	return (i);
}
