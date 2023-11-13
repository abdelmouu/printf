#include "main.h"

/**
 * print_rot - converts the input string to ROT13 and writes it to the buffer.
 * @arguments: The input string to convert.
 * @buf: The buffer pointer where the converted string will be written.
 * @ibuf: The index for the buffer pointer.
 *
 * Return: The number of characters printed to the buffer.
 */
int print_rot(va_list arguments, char *buf, unsigned int ibuf)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *strg;
	unsigned int i, j, m;
	char nil[] = "(avyy)";

	strg = va_arg(arguments, char *);
	if (strg == NULL)
	{
		for (i = 0; nil[i]; i++)
			ibuf = handl_buf(buf, nil[i], ibuf);
		return (6);
	}
	for (i = 0; strg[i]; i++)
	{
		for (m = j = 0; alf[j]; j++)
		{
			if (strg[i] == alf[j])
			{
				m = 1;
				ibuf = handl_buf(buf, rot[j], ibuf);
				break;
			}
		}
		if (m == 0)
			ibuf = handl_buf(buf, strg[i], ibuf);
	}
	return (i);
}
