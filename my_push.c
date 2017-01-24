#include "monty.h"

/**
 * my_push - push integer n onto stack
 * @head: start of stack
 * @line_number: line number in file
 * Return: void
 */
void my_push(stack_t **head, unsigned int line_number)
{
	(void) line_number;


	if (my_array[1] == 0)
		add_node_end(head, my_array[0]);
	else
		add_node(head, my_array[0]);
}

/**
 * my_pall - print everything in  stack
 * @head: start of stack
 * @line_number: line_number in file
 * Return: void
 */
void my_pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;


	if (*head != NULL)
	{
		temp = find_end(head);
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}

}

/**
 * my_pint - print first int in stack
 * @head: start of stack
 * @line_number: line number of line in file
 * Return: void
 */
void my_pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	printf("-------------------------------------------\n");
	temp = find_end(head);
	if (temp == NULL)
	{
		printf("L%u: can't print, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", temp->n);
}

/**
 * my_pop - "pop" the most recent item off stack
 * @head: start of stack
`* @line_number: line number in file
 * Return: void
 */
void my_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;


	if (*head == NULL)
	{
		printf("L%u: can't pop, empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = find_end(head);
	helptmp = temp->prev;
	if (helptmp != NULL)
		helptmp->next = NULL;
	else
		*head = NULL;
	free(temp);
}

/**
 * my_swap - swap the location of the top two values in the stack
 * @head: start of the stack
 * @line_number: the line number of command in the file
 * Return: void
 */
void my_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helptmp;
	int swap_n;

	temp = find_end(head);

	if (temp == NULL || temp->prev == NULL )
	{
		printf("L%u: can't swap, no space stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = temp->prev;

	swap_n = temp->n;
	temp->n = helptmp->n;
	helptmp->n = swap_n;
}
