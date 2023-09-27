#include "sort.h"

/**
 * max_value - returns the maximum value from
 * an array of integers
 * @arr: pointer to array
 * @size: size of array
 * Return: the maximum value of the array
 */
int max_value(int *arr, int size)
{
	int max = arr[0], i;

	for (i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array of integers using the counting
 * sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Retrun: nothing
 */
void counting_sort(int *array, size_t size)
{
	int *array_b, *count, k, i, n;

	if (array == NULL || size < 2)
		return;

	n = (int)size;
	k = max_value(array, n);

	array_b = malloc(sizeof(int) * n);
	if (array_b == NULL)
		return;

	count = malloc(sizeof(int) * k + 1);
	if (count == NULL)
	{
		free(array_b);
		return;
	}

	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[array[i]] += 1;

	for (i = 1; i <= (k + 1); i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);

	for (i = (n - 1); i >= 0; i--)
		array_b[--count[array[i]]] = array[i];

	for (i = 0; i < n; i++)
		array[i] = array_b[i];

	free(array_b);
	free(count);
}
