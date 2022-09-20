#include "lists.h"
/**
 * check_cycle - checks if singly linked list has a cycle
 * @list: pointer to head of list
 * Return: 0 if list has no cycle else 1
 */

int check_cycle(listint_t *list)
{
	listint_t *tortoise = NULL;
	listint_t *hare = NULL;

	if (list == NULL || list->next == NULL)
		return (0);

	tortoise = list;
	hare = tortoise->next;

	while (hare != NULL)
	{
		if (hare->next == NULL)
			return (0);

		hare = hare->next->next;
		tortoise = tortoise->next;

		if (hare == tortoise)
			return (1);
	}
	return (0);
}
