#include <stdio.h>
#include "sort.h"
#include <stdbool.h>

void bubble_sort(int *array, size_t size)
{
    size_t a, b, temp;
    bool swapped = false;

    for (a = 0; a < size; a++)
    {
        for (b = 0; b < size - 1; b++)
        {
            if (array[b] > array[b + 1])
            {
                temp = array[b];
                array[b] = array[b + 1];
                array[b + 1] = temp;
                print_array(array, size);

                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}
