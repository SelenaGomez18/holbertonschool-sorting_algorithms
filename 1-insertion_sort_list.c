#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *righter = NULL;

	if (list == NULL || *list == NULL)
		return;

	righter = (*list)->next;

	while (righter)
	{
		while ((righter->prev != NULL) && (righter->n < righter->prev->n))
		{
			righter->prev->next = righter->next;

			if (righter->next != NULL)
				righter->next->prev = righter->prev;

			righter->next = righter->prev;
			righter->prev = righter->prev->prev;
			righter->next->prev = righter;

			if (righter->prev == NULL)
				*list = righter;
			else
				righter->prev->next = righter;

			print_list(*list);
		}
		righter = righter->next;
	}
}
