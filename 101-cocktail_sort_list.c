#include "sort.h"

/**
 * swap - swaps two adjecent nodes in a doubly linked list
 * @list: pointer to pointer to the DDL
 * @a: pointer to first node
 * @b: pointer to second node
 * Return: nothing
 */
void swap(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *temp;

	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;

	b->prev = a->prev;
	a->prev = b;
	temp = b;
	a->next = b->next;
	temp->next = a;
}

/**
 * cocktail_sort_list - sorts a doubly liked list of integers
 * using the cocktail shaker sort algorithm
 * @list: pointer to pointer of the DDL
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	bool swapped;
	int i, range = 100000;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do
	{
		swapped = false;
		for (i = 0; temp->next && i < range; i++)
		{
			if (temp->n > temp->next->n)
			{
				swap(list, temp, temp->next);
				print_list(*list);
				swapped = true;
			}
			else
				temp = temp->next;
		}
		if (temp->next == NULL)
			range = i - 1;
		if (swapped)
		{
			swapped = false;
			temp = temp->prev;
		}

		for (i = 0; temp->prev && i < range; i++)
		{
			if (temp->n < temp->prev->n)
			{
				swap(list, temp->prev, temp);
				print_list(*list);
				swapped = true;
			}
			else
				temp = temp->prev;
		}
		if (swapped)
			temp = temp->next;
	} while (swapped);
}
