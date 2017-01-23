#include "monty.h"

/**
 * my_add - add the top two number of the stack together
 * @head: beginning of the stack
 * @line_number: line number of command in text
 * Return: nothing
 */
void my_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n + temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
	j = my_array[1];
	my_array[1] = 0;
	my_push(head, line_number);
	my_array[1] = j;
}

/**
 * my_nop - a function that does nothing
 * @head: useless input
 * @line_number: useless input
 * Return: nothing
 */
void my_nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	return;
}

/**
 * my_sub - subtract the top value from the second to top value
 * @head: beginning of the stack
 * @line_number: line number of command in stack
 * Return: nothing
 */
void my_sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n - temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}

/**
 * my_div - divide the second value by the top value
 * @head: beginning of the stack
 * @line_number: line number of command in stack
 * Return: nothing
 */
void my_div(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n / temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}

/**
 * my_mul - multiply the top two values together
 * @head: beginning of the satck
 * @line_number: line number of command in stack
 * Return: nothing
 */
void my_mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n * temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}