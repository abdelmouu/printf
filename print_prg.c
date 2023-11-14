#include "main.h"
#include <stdio.h>
/**
 * print_prg - prints a character to standard output.
 * @a: The character to print.
 * @buf: The buffer pointer.
 * @j: The index for the buffer pointer.
 *
 * Return: 1 on success.
 */
int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int j)
{
	handl_buf(buf, '%', j);

	return (1);
}
