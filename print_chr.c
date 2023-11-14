#include "main.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * print_chr - Writes a character to the buffer.
 *
 * This function writes the input character to the specified buffer
 * at the provided index.
 *
 * @arguments: Input character to be written.
 * @buf: Buffer pointer to write the character.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: Returns 1 on success.
 */
int print_chr(va_list arguments, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(arguments, int);
	handl_buf(buf, c, ibuf);

	return (1);
}
