#include "main.h"
/**
 * fill_short_oct_array - Convert binary array to a short octal representation
 * and store it in an array.
 *
 * This function converts a binary array into a short octal representation
 * and stores it in the provided octal array.
 *
 * @bnr: Array storing the binary input.
 * @oct: Array to hold the resulting short octal representation
 *
 * Return: The binary array.
 */
char *fill_short_oct_array(char *bnr, char *oct)
{
	int i, j, k, x, l;

	oct[6] = '\0';
	for (i = 15, x = 5; i >= 0; i--, x--)
	{
		if (i > 0)
			l = 4;
		else
			l = 1;
		for (op = 0, j = 1; j <= l; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[x] = op + '0';
	}
	return (oct);
}
