#include "main.h"
/**
 * fill_oct_array - Convert binary array to an octal representation
 * and store it in an array.
 *
 * This function transforms a binary array into an octal representation
 * and stores it in the provided octal array.
 *
 * @bnr: Array storing the binary input.
 * @oct: Array to hold the resulting octal representation.
 *
 * Return: The binary array.
 */

char *fill_oct_array(char *bnr, char *oct)
{
	int i, j, k, x, l;

	oct[11] = '\0';
	for (i = 31, x = 10; i >= 0; i--, x--)
	{
		if (i > 1)
			l = 4;
		else
			l = 2;
		for (k = 0, j = 1; j <= l; j *= 2, i--)
			k = ((bnr[i] - '0') * j) + k;
		i++;
		oct[x] = k + '0';
	}
	return (oct);
}
