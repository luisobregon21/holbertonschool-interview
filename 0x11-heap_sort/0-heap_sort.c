#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL)
		return;
	for (i = size / 2; i > 0; i--)
		heap_root(array, size, i - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heap_root(array, i, 0, size);
	}
}

/**
 * heap_root - ...
 *
 * @arr: ...
 * @n: ...
 * @i: ...
 * @size: ...
 */
void heap_root(int *arr, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest], arr, size);
		heap_root(arr, n, largest, size);
	}
}

/**
 * swap - swaps int in an array
 *
 * @a: int a
 * @b: int b
 * @array: array to be sorted
 * @n: array size
 */
void swap(int *a, int *b, int *array, size_t n)
{
	int temp = *a;

	*a = *b;
	*b = temp;
	print_array(array, n);
}
