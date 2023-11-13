#include "main.h"
/**
 * * fill_hex_array - Convert binary array to a hexadecimal representation
 * and store it in an array.
 *
 * This function transforms a binary array into a hexadecimal representation
 * and stores it in the provided hexadecimal array.
 *
 * @bnr: Array storing the binary input.
 * @hex: Array to hold the resulting hexadecimal representation.
 * @isupp: An integer determining the case (uppercase/lowercase)
 * of the hexadecimal letters.
 * @limit: Size of the hexadecimal array.
 *
 * Return: The binary array.
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int i, j, k, x;

	hex[limit] = '\0';
	if (isupp)
		x = 55;
	else
		x = 87;
	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (k = 0, j = 1; j <= 8; j *= 2, i--)
			k = ((bnr[i] - '0') * j) + k;
		i++;
		if (k < 10)
			hex[i / 4] = k + 48;
		else
			hex[i / 4] = k + x;
	}
	return (hex);
}
