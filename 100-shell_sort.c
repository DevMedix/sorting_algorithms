#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the shell sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int i, j, gap = 1;
	int temp, n = (int)size;

	if (array == NULL || size < 2)
		return;

	while (gap < n / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (j = gap; j < n; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i] > array[i + gap])
				{
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
				}
				else
					break;
			}
		}
		print_array(array, size);
	}
}
