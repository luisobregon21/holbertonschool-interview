#include "holberton.h"

/**
 * main - Entry point for a program that multiplies two positive numbers
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: result
 */
int main(int argc, char **argv)
{
	int idx, idx2, l1, l2, len, mul, sum, ten, ten2, tl, zer = 0;
	char *res;

	if (argc != 3 || _isnumber(argv[1]) == 0 || _isnumber(argv[2]) == 0)
		printf("Error\n"), exit(98);
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
		printf("0\n"), exit(0);
	l1 = strlen(argv[1]), l2 = strlen(argv[2]);
	len = l1 + l2;
	res = _alloc(len);
	if (res == 0)
		printf("Error\n"), exit(98);
	for (idx = l2 - 1; idx >= 0; idx--)
	{
		ten = 0, ten2 = 0;
		for (idx2 = l1 - 1; idx2 >= 0; idx2--)
		{
			tl = idx + idx2 + 1;
			mul = (argv[1][idx2] - '0') * (argv[2][idx] - '0') + ten;
			ten = mul / 10;
			sum = (res[tl] - '0') + (mul % 10) + ten2;
			ten2 = sum / 10;
			res[tl] = (sum % 10) + '0';
		}
		res[tl - 1] = (ten + ten2) + '0';
	}
	if (res[0] == '0')
		zer = 1;
	for (; zer < len; zer++)
		printf("%c", res[zer]);
	printf("\n");
	free(res);
	return (0);
}

/**
 * _isnumber - ...
 *
 * @str: ...
 * Return: ...
 */
int _isnumber(char *str)
{
	int idx, check, d;

	d = 0, check = 1;
	for (idx = 0; *(str + idx) != 0; idx++)
	{
		d = isdigit(*(str + idx));
		if (d == 0)
		{
			check = 0;
			break;
		}
	}
	return (check);
}

/**
 * _alloc - ...
 *
 * @nmemb: ...
 * Return: ...
 */
char *_alloc(unsigned int nmemb)
{
	unsigned int idx;
	char *p;

	p = malloc(nmemb + 1);
	if (p == 0)
		return (0);
	for (idx = 0; idx < nmemb; idx++)
		p[idx] = '0';
	p[idx] = '\0';
	return (p);
}
