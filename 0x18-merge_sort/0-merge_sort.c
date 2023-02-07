#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using the merge sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array && size >= 2)
        split_arrays(array, 0, size - 1);
}

/**
 * split_arrays - ...
 *
 * @array: ...
 * @start: ...
 * @end: ...
 */
void split_arrays(int *array, int start, int end)
{
    int mid = (start + end - 1) / 2;

    if (start < end)
    {
        split_arrays(array, start, mid);
        split_arrays(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

/**
 * merge - ...
 *
 * @array: ...
 * @start: ...
 * @mid: ...
 * @end: ...
 */
void merge(int *array, int start, int mid, int end)
{
    int left_iter, right_iter;
    int left_size = mid - start + 1;
    int right_size = end - mid;

#pragma GCC diagnostic ignored "-Wvla"
    int left[left_size];
    int right[right_size];

    for (left_iter = 0; left_iter < left_size; left_iter++)
        left[left_iter] = array[start + left_iter];
    for (right_iter = 0; right_iter < right_size; right_iter++)
        right[right_iter] = array[mid + right_iter + 1];
    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);
    sort(array, left, right, start, mid, end);
    printf("[Done]: ");
    print_array(&array[start], left_size + right_size);
}

/**
 * sort - ...
 *
 * @arr: ...
 * @l: ...
 * @r: ...
 * @start: ...
 * @mid: ...
 * @end: ...
 */
void sort(int *arr, int *l, int *r, int start, int mid, int end)
{
    int left_iter, right_iter, array_iter;
    int left_size = mid - start + 1;
    int right_size = end - mid;

    left_iter = right_iter = 0;
    array_iter = start;

    while (left_iter < left_size && right_iter < right_size)
    {
        if (l[left_iter] < r[right_iter])
        {
            arr[array_iter] = l[left_iter];
            left_iter++;
        }
        else
        {
            arr[array_iter] = r[right_iter];
            right_iter++;
        }
        array_iter++;
    }
    while (left_iter < left_size)
    {
        arr[array_iter] = l[left_iter];
        left_iter++;
        array_iter++;
    }
    while (right_iter < right_size)
    {
        arr[array_iter] = r[right_iter];
        right_iter++;
        array_iter++;
    }
}
