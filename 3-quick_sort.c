#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two integer variables using their pointers
 * @a: pointer first integer
 * @b: pointer to second integer
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - implements the lomuto partition scheme
 * @arr: pointer to array
 * @size: size of array
 * @low: begins partion
 * @high: ends partition
 * Return: nothing
 */
int lomuto_partition(int *arr, size_t size, int low, int high)
{
	int pivot  = arr[high];
	int j, i = low;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			if (arr[i] != arr[j])
				print_array(arr, size);
			i++;
		}
	}

	swap(&arr[i], &arr[high]);
	if (arr[i] != arr[high])
		print_array(arr, size);
	return (i);
}

/**
 * lomuto_quick_sort - recursives sorts an array of integrs using
 * the quick sort algorithm
 * @arr: pointer to array to sort
 * @size: size of array
 * @low: index that begins partition
 * @high: index that ends partition
 * Return: nothing
 */
void lomuto_quick_sort(int *arr, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(arr, size, low, high);

		lomuto_quick_sort(arr, size, low, pi - 1);
		lomuto_quick_sort(arr, size, pi + 1, high);
	}
}

/**
 * quick_sort - sorts arrays of integers in asceding order
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, size, 0, (int)size - 1);
}
