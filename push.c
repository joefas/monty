#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (tap.arg)
	{
		if (tap.arg[0] == '-')
			j++;
		for (; tap.arg[j] != '\0'; j++)
		{
			if (tap.arg[j] > 10 || tap.arg[j] < 1)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			free(tap.content);
			fclose(tap.file);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(tap.file);
		free(tap.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }

	n = atoi(tap.arg);
	if (tap.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
