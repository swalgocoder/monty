#include "monty.h"


/**
 * my_mod - the mod of the top number from the second to top numbers
 * @head: start of the stack
 * @line_number: the line number of command in file
 * Return: void
 */
void my_mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int i, j;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mod, no space in stack \n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = temp->prev;
	i = helptmp->n % temp->n;
	my_array[0] = i;
	my_pop(head, line_number);
	my_pop(head, line_number);
        j = my_array[1];
        my_array[1] = 0;
        my_push(head, line_number);
        my_array[1] = j;
}

/**
 * my_pchar - print the value at top of the stack as a character
 * @head: start of the stack
 * @line_number: line number of command in file
 * Return: void
 */
void my_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = find_end(head);
	if (temp == NULL)
	{
		printf("L%u: can't print char, out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 32 && temp->n <= 127)
		printf("%c\n", temp->n);
	else
	{
		printf("L%u: can't print char, out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * my_pstr - print the entire stack as a string
 * @head: start of the stack
 * @line_number: line number of command in file
 * Return: void
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
 * my_rotl - move the value from top to bottom of stack
 * @head: start of the stack
 * @line_number: line number of command in file
 * Return: void
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
 * my_rotr - move the value from the bottom to top of the stack
 * @head: start of the stack
 * @line_number: line number of command in file
 * Return: void
*/
void my_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	(void) line_number;

	temp = *head;
	add_node_end(head, temp->n);
	helptmp = temp->next;
	helptmp->prev = NULL;
	*head = helptmp;
	free(temp);
}
