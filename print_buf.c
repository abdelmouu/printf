#include "main.h"

/**
 * print_buf - Prints the contents of a buffer.
 *
 * This function prints the contents of the specified buffer
 * up to the given number of bytes.
 *
 * @buf: Pointer to the buffer to be printed.
 * @nbuf: Number of bytes to print from the buffer.
 *
 * Return: The number of bytes actually printed.
 */
int print_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
