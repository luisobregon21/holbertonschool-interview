#include "menger.h"

/**
 * menger - 2D menger sponge
 * @level: level of the menger sponge
 */

void menger(int level)
{
	int size, row, col;
	char character;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			character = getChar(row, col);
			printf("%c", character);
		}
		printf("\n");
	}
}
/**
 * getChar - gets the character
 * @row: gets the row
 * @col: gets the col
 * Return: the '#' character
 */
char getChar(int row, int col)
{
	while (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
	}
	return ('#');
}
