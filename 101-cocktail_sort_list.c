#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		for (current = start; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;

		end = current;
		swapped = 0;

		for (current = end; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current, current->prev);
				print_list(*list);
				swapped = 1;
			}
		}

		start = current;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to a pointer to the head of the list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp = NULL;

	if (*list == NULL || node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	temp = node1->prev;
	node1->prev = node2;
	node2->prev = temp;

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	if (node1->prev == NULL)
		*list = node1;

	if (node2->next == NULL)
		*list = node2;
}
