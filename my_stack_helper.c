#include "monty.h"

/**
 * add_node_end - add node("n" to "push") to the end of stack
 * @head: start of the stack
 * @n: value to add to the linked list
 * Return: pointer to new_node
 */
stack_t *addnode_2_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;


	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (new_node);
}

/**
 * find_end - find the end of the stack
 * @head: start of stack
 * Return: last item in the stack
 */
stack_t *find_stk_end(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

/**
 * add_node - add node at the start of the stack
 * @head: start of stack
 * @n: value to add
 * Return: start of the stack
 */
stack_t *add_mynode(stack_t **head, const int n)
{
	stack_t *new_node, *temp;


	temp = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL;

	new_node->next = *head;
	new_node->n = n;
	if (temp != NULL)
		temp->prev = new_node;

	*head = new_node;
	return (new_node);
}
