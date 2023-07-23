#include "sort.h"

/**
 * swapper - function that swaps two nodes updating its prev
 * and next appropriately
 *
 * @list: the list to be swapped
 * @node: pointer to a pointer node
 *
 * Return: nothing
 */
void swapper(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using cocktail shaker sort
 *
 * @list: pointer to pointer of head of doubly linked list
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	swapped = 1;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swapper(list, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;
		swapped = 0;

		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swapper(list, current->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
