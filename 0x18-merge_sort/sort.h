#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_arrays(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);
void sort(int *arr, int *l, int *r, int start, int mid, int end);

#endif
