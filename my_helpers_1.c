#include "monty.h"

/**
 * my_add - add the top two number of the stack in a batch
 * @head: beginning of the stack
 * @line_number: line number of command in text
 * Return: void
 */
void my_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int i, j;

	temp = find_end(head);
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
 * @head: null input
 * @line_number: null input
 * Return: void
 */
void my_nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	return;
}

/**
 * my_sub - subtract the top n(value) from the second(vs.top)
 * @head: beginning of the stack
 * @line_number: line number of command in stack
 * Return: void
 */
void my_sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't sub, no space in stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = temp->prev;
	i = helptmp->n - temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}

/**
 * my_div - divide the second n by the top n
 * @head: beginning of the stack
 * @line_number: line number of command in stack
 * Return: nothing
 */
void my_div(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = temp->prev;
	i = helptmp->n / temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}

/**
 * my_mul - multiplication of the top two values
 * @head: beginning of the satck
 * @line_number: line number of command in stack
 * Return: void
 */
void my_mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = temp->prev;
	i = helptmp->n * temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}
