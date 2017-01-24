#include "monty.h"

/**
 * my_add - add the top two n(values) of the stack in a batch
 * @head_ref: start of the stack
 * @line_number: line number of command in text
 * Return: void
 */
void my_add(stack_t **head_ref, unsigned int line_number)
{
	stack_t *tmp_node, *helptmp;
	int i, j;

	tmp_node = find_stk_end(head_ref);
	if (tmp_node == NULL || tmp_node->prev == NULL)
	{
		printf("L%u: can't add, no space in stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = tmp_node->prev; /*referencing the top 2 items*/
	i = helptmp->n + tmp_node->n; /*add them*/
	my_array[0] = i;
	my_pop(head_ref, line_number);/*after adding, top 2 items deleted*/
	my_pop(head_ref, line_number);
	j = my_array[1];
	my_array[1] = 0; /* as arguments for my_push()*/
	my_push(head_ref, line_number);
	my_array[1] = j;
}

/**
 * my_nop - does nothing
 * @head_ref: input
 * @line_number: input
 * Return: void
 */
void my_nop(stack_t **head_ref, unsigned int line_number)
{
	(void) head_ref;
	(void) line_number;
	return;
}

