#include "sort.h"

void sift_down(int *array, size_t size, size_t start, size_t end);
void heapify(int *array, size_t size);

/**
 * heap_sort - sorts array in asending order using heap sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t end;

	if (array == NULL || size < 2)
	{
		return;
	}

	heapify(array, size);

	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;

		print_array(array, size);
		sift_down(array, size, 0, end - 1);

		end--;
	}
}


/**
 * sift_down - function to shift array
 * @array: array to sort
 * @size: size of array
 * @start: first element of array
 * @end: last element of array
 *
 * Return: void
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	int temp;
	size_t root = start;
	size_t left_child, right_child, swap;

	while (2 * root + 1 <= end)
	{
		left_child = 2 * root + 1;
		right_child = 2 * root + 2;
		swap = root;

		if (array[swap] < array[left_child])
		{
			swap = left_child;
		}

		if (right_child <= end && array[swap] < array[right_child])
		{
			swap = right_child;
		}

		if (swap == root)
		{
			return;
		}
		else
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;

			print_array(array, size);

			root = swap;
		}
	}
}


/**
 * heapify - function to combine heap
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void heapify(int *array, size_t size)
{
	size_t start = (size / 2) - 1;

	while (start > 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}

	sift_down(array, size, 0, size - 1);
}
