#include "lists.h"

int linked_list_len(listint_t **head);
int check_palindrome_bruteforce(listint_t **head);
int check_palindrome_reverse_half(listint_t **head);
listint_t *reverse(listint_t *start);

/**
 * is_palindrome - checks if a singly-linked list is a palindrome
 * @head: Pointer to head of list.
 *
 * Return: 0 if its not a palindrome or 1 if it is.
 */

int is_palindrome(listint_t **head)
{
	/* If list is empty or has only one node */
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	/* If list has only 2 nodes */
	if ((*head)->next->next == NULL)
		return ((*head)->n == (*head)->next->n ? 1 : 0);

	/* If list has only 3 nodes */
	if ((*head)->next->next->next == NULL)
		return ((*head)->n == (*head)->next->next->n ? 1 : 0);

	/* If list has more than 3 nodes */
	return (check_palindrome_reverse_half(head));
}

/**
 * check_palindrome_reverse_half - checks if a singly-link list is a palindrome
 * @head: Pointer to head of list.
 *
 * This algorithm uses 2 pointers to track the middle of the list,
 * then reversing the second half and then comparing the respective elements.
 * It has a time complexity of 0(n) since the list is only traversed once.
 *
 * Return: 0 if its not a palindrome or 1 if it is.
 */

int check_palindrome_reverse_half(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;

	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverse(slow->next);
	slow = slow->next;
	fast = *head;

	while (slow)
	{
		if (fast->n != slow->n)
			return (false);
		slow = slow->next;
		fast = fast->next;
	}

	return (true);
}

/**
 * check_palindrome_bruteforce - checks if a singly-linked list is a palindrome
 * @head: Pointer to head of list.
 *
 * This algorithm gets the length of the list, then allocates an array
 * of integers where the numbers from the list are copied to.
 * It then uses array indexing to track adjacent numbers starting from
 * the middle of the list.
 * It has a time complexity of 0(n^3) since the list is traversed 3 times,
 * when getting the length, when copying the numbers and when comparing.
 *
 * Return: 0 if its not a palindrome or 1 if it is.
 */

int check_palindrome_bruteforce(listint_t **head)
{
	int x, list_len, left_idx, right_idx;
	int *numbers;
	listint_t *curr = *head;

	list_len = linked_list_len(head);

	/* Allocate an array to store the integers from the lists' nodes */
	numbers = malloc(sizeof(int) * list_len);
	if (!numbers)
		return (false);

	/* Copy over the integers from each node into the new array */
	curr = *head;
	for (x = 0; x < list_len; x++, curr = curr->next)
		numbers[x] = curr->n;

	if ((list_len & 1) == 0)
	{ /* If there's an even number of nodes int the list */
		right_idx = list_len / 2;
		left_idx = right_idx - 1;
	}
	else if ((list_len & 1) == 1)
	{ /* If there's an odd number of nodes in the list */
		right_idx = (list_len / 2) + 1;
		left_idx = (list_len / 2) - 1;
	}
	for ( ; left_idx >= 0; left_idx--, right_idx++)
		if (numbers[left_idx] != numbers[right_idx])
		{
			free(numbers);
			return (false);
		}

	free(numbers);
	return (true);
}

/**
 * linked_list_len - returns the length of a linked list
 * @head: Pointer to head of list.
 *
 * Return: Integer, the length of the list.
 */

int linked_list_len(listint_t **head)
{
	listint_t *curr = *head;
	int list_len = 1;

	while (curr->next)
	{ /* Get the length of the list */
		list_len++;
		curr = curr->next;
	}

	return (list_len);
}

/**
 * reverse - reverses a linked-list starting from a specified node
 * @start: Node to start reversing from.
 *
 * Return: Pointer to the first node after list has been reversed.
 */

listint_t *reverse(listint_t *start)
{
	listint_t *next = NULL;
	listint_t *prev = NULL;

	while (start)
	{
		next = start->next;
		start->next = prev;
		prev = start;
		start = next;
	}

	start = prev;
	return (start);
}
