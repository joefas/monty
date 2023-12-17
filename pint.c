#include "monty.h"
/**
 * f_pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line_number in the source file
 * Return: No return value
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(tap.file);
		free(tap.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
