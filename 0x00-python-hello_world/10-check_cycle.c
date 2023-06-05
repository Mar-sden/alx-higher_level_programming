#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has
 * a cycle in it
 * @list: pointer to the list
 * Return: 0 if there is no cycle,
 * 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *p3;
	listint_t *prev;

	p3 = list;
	prev = list;
	while (list && p3 && p3->next)
	{
		list = list->next;
		p3 = p3->next->next;

		if (list == p3)
		{
			list = prev;
			prev =  p3;
			while (1)
			{
				p3 = prev;
				while (p3->next != list && p3->next != prev)
				{
					p3 = p3->next;
				}
				if (p3->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
