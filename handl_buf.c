#include "main.h"

/**
 * handl_buf - Concatenates a character to the buffer.
 *
 * This function concatenates a character to the buffer pointer
 * at the specified index.
 *
 * @buf: Pointer to the buffer.
 * @c: Character to concatenate.
 * @ibuf: Index of the buffer pointer.
 *
 * Return: The updated index of the buffer pointer.
 */

unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		print_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
