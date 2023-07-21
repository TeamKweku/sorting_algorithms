#include "sort.h"

void swapper(listint_t **list, listint_t **node1, listint_t *node2);

/**
 * insertion_sort_list - function that sorts a doubly linked
 * list of integers in ascending order
 *
 * @list: pointer to the head of the list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *sorted, *temp;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = temp)
	{
		temp = curr->next;
		sorted = curr->prev;

		while (sorted != NULL && curr->n < sorted->n)
		{
			swapper(list, &sorted, curr);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swapper - function that swaps two nodes updating its prev
 * and next appropriately
 *
 * @list: the list to be swapped
 * @node1: pointer to a pointer node
 * @node2: pointer to a node
 *
 * Return: nothing
 */
void swapper(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}
