#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * check_palindrome - function that traverse each node in parallel
 * @head: head of linked list
 * @tail: tail of linked list
 * Return: 1 if is a palindrome otherwise 0
 */
int check_palindrome(listint_t **head, listint_t *tail)
{
	if (tail == NULL)
		return (1);

	if (check_palindrome(head, tail->next) && (*head)->n == tail->n)
	{
		*head = (*head)->next;
		return (1);
	}

	return (0);
}

/**
 * is_palindrome - Check if the linked list is a palindrome
 * @head: head of node
 * Return: 1 if is a palindrome 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL && *head == NULL)
		return (1);
	return (check_palindrome(head, *head));
}

