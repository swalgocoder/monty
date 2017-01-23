#include "monty.h"

/**
 * my_mod - find the mod of the top number from the second to top numbers
 * @head: beginning of the stack
 * @line_number: the line number of command in file
 * Return: nothing
 */
void my_mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n % temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}

/**
 * my_pchar - print out the value at top of the stack as a character
 * @head: beginning of the stack
 * @line_number: line number of command in file
 * Return: nothing
 */
void my_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = find_end(head);
	if (temp == NULL)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 32 && temp->n <= 127)
		printf("%c\n", temp->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * my_pstr - print out the entire stack as a string
 * @head: beginning of the stack
 * @line_number: line number of command in file
 * Return: nothing
 */
void my_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = find_end(head);
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}

/**
 * my_rotl - move the value from top of stack to bottom of stack
 * @head: beginning of the stack
 * @line_number: line number of command in file
 * Return:; nothing
*/
void my_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = find_end(head);
	add_node(head, temp->n);
	while (temp != NULL)
	{
		printf("rotl %d\n", temp->n);
		temp = temp->prev;
	}
	my_pop(head, line_number);
}

/**
 * my_rotr - move the value from the bottom of the stack to top
 * @head: beginning of the stack
 * @line_number: lnie number of command in file
 * Return: nothing
*/
void my_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	(void) line_number;

	temp = *head;
	add_node_end(head, temp->n);
	helper = temp->next;
	helper->prev = NULL;
	*head = helper;
	free(temp);
}
