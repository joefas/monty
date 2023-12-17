#include "monty.h"
/**
 * addnode - add node to the head stack
 * @n: new_value
 * @head: head of the stack
 * Return: 0 always
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (aux)
		aux->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
}
