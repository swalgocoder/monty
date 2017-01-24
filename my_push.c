#include "monty.h"

/**
 * my_push - push integer n onto stack
 * @head_ref: start of stack
 * @line_number: line number in file
 * Return: void
 */
void my_push(stack_t **head_ref, unsigned int line_number)
{
	(void) line_number;


	if (my_array[1] == 0) /*stack empty*/
	  addnode_2_end(head_ref, my_array[0]); /*push n to the end of stack*/
	else
	  add_mynode(head_ref, my_array[0]);/*else push n to the top of stack*/
}

/**
 * my_pall - print everything in  stack
 * @head_ref: start of stack
 * @line_number: line_number in file
 * Return: void
 */
void my_pall(stack_t **head_ref, unsigned int line_number)
{
	stack_t *tmp_node;
	(void) line_number;


	if (*head_ref != NULL)
	{
		tmp_node = find_stk_end(head_ref);
		while (tmp_node != NULL)
		{
			printf("%d\n", tmp_node->n);
			tmp_node = tmp_node->prev; /*last in first out*/
		}
	}

}

/**
 * my_pint - print first int in stack
 * @head_ref: start of stack
 * @line_number: line number of line in file
 * Return: void
 */
void my_pint(stack_t **head_ref, unsigned int line_number)
{
	stack_t *tmp_node;


	tmp_node = find_stk_end(head_ref);
	if (tmp_node == NULL)
	{
		printf("L%u: can't print, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	  printf("%d\n", tmp_node->n); /*first in first out*/
}

/**
 * my_pop - "pop" the most recent item off stack
 * @head_ref: start of stack
`* @line_number: line number in file
 * Return: void
 */
void my_pop(stack_t **head_ref, unsigned int line_number)
{
	stack_t *tmp_node, *helptmp;


	if (*head_ref == NULL)
	{
		printf("L%u: can't pop, empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_node = find_stk_end(head_ref); /*tmp_node points to the bottom of stack*/
	helptmp = tmp_node->prev; /* referencing the most recent one*/
	if (helptmp != NULL)
		helptmp->next = NULL;
	else
	        *head_ref = NULL; /*resetting head_ref*/
	free(tmp_node); /*pop it out, deleting it*/
}

/**
 * my_swap - swap the location of the top two values in the stack
 * @head_ref: start of the stack
 * @line_number: the line number of command in the file
 * Return: void
 */
void my_swap(stack_t **head_ref, unsigned int line_number)
{
	stack_t *tmp_node, *helptmp;
	int swap_n;

	tmp_node = find_stk_end(head_ref);

	if (tmp_node == NULL || tmp_node->prev == NULL )
	{
		printf("L%u: can't swap, no space stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	helptmp = tmp_node->prev; /*referencing the recent "top" items*/

	swap_n = tmp_node->n;
	tmp_node->n = helptmp->n;
	helptmp->n = swap_n;
}
