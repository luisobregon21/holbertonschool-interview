#include "lists.h"
#include <stdlib.h>

listint_t *create_node(listint_t *point, int num);
/**
 * *insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the pointer of the head.
 * @number: the value the data will have.
 * Return: address of the new node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = *head, *new;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	if (tmp == NULL)
	{
		return (&new);
	}

	while (number > tmp->n)
	{
		if (tmp == NULL || tmp->next == NULL)
			return (NULL);

		if (tmp->next->n > number)
		{
			new->n = number;
			new->next = tmp->next;
			tmp->next = new;

			return (new);
		}

		tmp = tmp->next;
	}
	return (NULL);
}
