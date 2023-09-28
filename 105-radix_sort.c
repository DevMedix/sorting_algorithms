#include "sort.h"

/**
 * get_max - get the maximum element in array
 * @array: array to sort
 * @size: size of array
 *
 * Return: returns the maximum number
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * new_counting_sort - sorts array using count sort
 * @array: array to sort
 * @size: size of array
 * @exp: third parameter
 * Return: void
 */
void new_counting_sort(int *array, size_t size, int exp)
{

	size_t j, i;
	int k, b;

	int count[10] = {0};

	int *output = malloc(sizeof(int) * size);

	if (output == NULL)
	{
		return;
	}

	for (j = 0; j < size; j++)
	{
		count[(array[j] / exp) % 10]++;
	}

	for (k = 1; k < 10; k++)
	{
	count[k] += count[k - 1];
	}

	for (b = size - 1; b >= 0; b--)
	{
		output[count[(array[b] / exp) % 10] - 1] = array[b];
		count[(array[b] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - sorts array using radix algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
	{
		return;
	}

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		new_counting_sort(array, size, exp);
	}
}
