#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *hold, *temp, *sorter;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list);
	sorter = curr->next;

	while (sorter != NULL)
	{
		hold = sorter->next;
		while (curr != NULL && sorter->n < curr->n)
		{
			if (curr->prev != NULL)
				curr->prev->next = sorter;
			else
				*list = sorter;

			if (sorter->next != NULL)
				sorter->next->prev = curr;

			temp = sorter->next;
			sorter->next = curr;
			sorter->prev = curr->prev;
			curr->next = temp;
			curr->prev = sorter;

			print_list(*list);
			curr = sorter->prev;
		}
		sorter = hold;
		if (sorter != NULL)
			curr = sorter->prev;
	}
}
