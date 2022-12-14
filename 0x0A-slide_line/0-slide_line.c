#include "slide_line.h"

/**
 * merge_right - Function to move numbers right
 * @line: pointer to an array of integers 
 * @size: size of the array
 * Return: 1 on success or 0 on failure 
 */

int merge_right(int *line, size_t size)
{
	int num_1 = 0;
	int num_2 = 0;
	size_t move = size - 1;
	size_t idx;

	for (idx = size - 1; idx < size; idx--)
	{
		if (line[idx] != 0 && num_1 == 0)
		{
			num_1 = line[idx];
		}
		else if (line[idx] != 0 && num_1 != 0)
		{
			num_2 = line[idx];
		}
		if (num_1 != 0 && num_2 != 0)
		{
			if (num_1 == num_2)
			{
				line[move--] = num_1 + num_2;
				num_1 = 0;
				num_2 = 0;
			}
			else
			{
				line[move--] = num_1;
				num_1 = num_2;
				num_2 = 0;
				if (idx == 0)
				{
					line[move--] = num_1;
				}
			}

		}
		else if (num_1 != num_2 && idx == 0)
		{
			line[move--] = num_1;
		}
	}
	for (idx = 0; idx < move + 1; idx++)
	{
		line[idx] = 0;
	}
	return (1);
}

/**
 * moerge_left - moves numbers left
 * @line: pointer to an array of integers 
 * @size: size of the array
 * Return: 1 on success or 0 on failure 
 */
int merge_left(int *line, size_t size)
{
	int num_1 = 0;
	int num_2 = 0;
	size_t count = 0, idx;


	for (idx = 0; idx < size; idx++)
	{
		if (line[idx] != 0 && num_1 == 0)
		{
			num_1 = line[idx];
		}
		else if (line[idx] != 0 && num_1 != 0)
		{
			num_2 = line[idx];
		}
		if (num_1 != 0 && num_2 != 0)
		{
			if (num_1 == num_2)
			{
				line[count++] = num_1 + num_2;
				num_1 = 0;
				num_2 = 0;
			}
			else
			{
				line[count++] = num_1;
				num_1 = num_2;
				num_2 = 0;
				if (idx == size - 1)
				{
					line[count++] = num_1;
				}
			}
		}
		else if (num_1 != num_2 && idx == size - 1)
		{
			line[count++] = num_1;
		}
	}
	for (idx = count; idx < size; idx++)
	{
		line[idx] = 0;
	}
	return (1);
}

/**
 * slide_line - slides and merges an array of integers
 * 
 * @line: pointer to an array of integers 
 * @size: size of the array
 * @direction: direction to slide and merge the integers.
 * Return: 1 on success or 0 on failure 
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}
    
    if (direction == SLIDE_RIGHT)
    {
        return (merge_right(line, size));
    }
    return (merge_left(line, size));
}
