#include "monty.h"

/**
 * add_node_end - add node("n" to "push") to the end of stack
 * @head_ref: start of the stack, a list is represented by head_ref
 * @n: value to add to the linked list
 * Return: pointer to new_node
 */
stack_t *addnode_2_end(stack_t **head_ref, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t)) , *tmp_node;


	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL; /*avoid inserting invalid ptr to end of list*/
	if (*head_ref == NULL) /*if head empty, new node is the head*/
		*head_ref = new_node;
	else
	{
	        tmp_node = *head_ref;
		while (tmp_node->next != NULL)
			tmp_node = tmp_node->next;
		tmp_node->next = new_node;
		new_node->prev = tmp_node;
	}
	return (new_node);
}

/**
 * find_end - find the end of the stack
 * @head_ref: start of stack
 * Return: last item in the stack
 */
stack_t *find_stk_end(stack_t **head_ref)
{
	stack_t *tmp_node;

	tmp_node = *head_ref;
	while (tmp_node->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	return (tmp_node);
}

/**
 * add_node - add node at the start of the stack
 * @head_ref: start of stack
 * @n: value to add
 * Return: start of the stack
 */
stack_t *add_mynode(stack_t **head_ref, const int n)
{
	stack_t *new_node = new_node = malloc(sizeof(stack_t)), *tmp_node;


	if (new_node == NULL)
		return (NULL);

	tmp_node = *head_ref;
	new_node->prev = NULL;

	new_node->next = *head_ref;
	new_node->n = n;
	if (tmp_node != NULL)
		tmp_node->prev = new_node;

	*head_ref = new_node;
	return (new_node);
}
