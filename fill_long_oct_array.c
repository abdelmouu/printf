#include "main.h"
/**
 * fill_long_oct_array - Convert binary array to a long octal representation
 * and store it in an array.
 *
 * This function converts a binary array into a long octal representation
 * and stores it in the provided octal array.
 *
 * @bnr: Array storing the binary input.
 * @oct: Array to hold the resulting long octal representation.
 *
 * Return: The binary array.
 */

char *fill_long_oct_array(char *bnr, char *oct)
{
	int i, j, k, x, l;

	oct[22] = '\0';
	for (i = 63, x = 21; i >= 0; i--, x--)
	{
		if (i > 0)
			l = 4;
		else
			l = 1;
		for (k = 0, j = 1; j <= l; j *= 2, i--)
			k = ((bnr[i] - '0') * j) + k;
		i++;
		oct[x] = k + '0';
	}
	return (oct);
}
