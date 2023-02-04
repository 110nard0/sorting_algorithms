#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list of integers in ascending order
 * using Insertion sort algorithm
 * @list: double pointer to a doubly linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (!list || !(*list) || !(*list)->next)
		return;

	node = (*list)->next;
	while (node)
	{
		while (node->prev && node->n < node->prev->n)
		{
			/* Swap nodes if value is higher than previous */
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			node->next = node->prev;
			node->prev = node->prev->prev;
			node->next->prev = node;

			/* Adjust next pointer of prev node to point to node */
			if (node->prev)
				node->prev->next = node;
			/* Update list to point to current node as new head */
			else
				*list = node;
			print_list(*list);
		}
		node = node->next;
	}
}
