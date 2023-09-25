#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int lomuto_partition(int *arr, size_t size, int low, int high)
{
	int pivot  = arr[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}

void lomuto_quick_sort(int *arr, size_t size, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(arr, size, low, high);

		lomuto_quick_sort(arr, size, low, pi - 1);
		lomuto_quick_sort(arr, size, pi + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, size, 0, size - 1);
}
