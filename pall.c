#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: number used
 * Return: Always 0
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;

	if (h != NULL)
	{
		while (h)
		{
			printf("%d\n", h->n);
			h = h->next;
		}
	}
}
