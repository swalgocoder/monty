#include "monty.h"

/**
 * my_add - add the top two n(values) of the stack in a batch
 * @head: start of the stack
 * @line_number: line number of command in text
 * Return: void
 */
void my_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int i, j;

	temp = find_stk_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't add, no space in stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = temp->prev;
	i = helptmp->n + temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
	j = my_array[1];
	my_array[1] = 0;
	my_push(head, line_number);
	my_array[1] = j;
}

/**
 * my_nop - does nothing
 * @head: input
 * @line_number: input
 * Return: void
 */
void my_nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	return;
}

