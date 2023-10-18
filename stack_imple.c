#include "monty.h"

/**
 * push_element - Pushes a new element onto the stack.
 * @top: Pointer to the top of the stack.
 * @value: Value to be pushed onto the stack.
 *
 * Return: void
 */
void push_element(stack_t **top, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Stack Overflow\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!(*top))
	{
		*top = new_node;
	}
	else
	{
		new_node->next = *top;
		(*top)->prev = new_node;
		(*top) = new_node;
	}
}

/**
 * print_stack - Prints all elements of the stack.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter.
 *
 * This function prints the elements of the stack.
 */
void print_stack(stack_t **top, unsigned int value)
{
	stack_t *temp;
	(void)value;

	if (!(*top))
	{
		fprintf(stderr, "Stack underflow\n");
		return;
	}
	else
	{
		temp = *top;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
/**
 * free_stack - Frees a stack.
 * @top: Pointer to the top of the stack.
 *
 * This function frees all the nodes in the stack.
 */
void free_stack(stack_t *top)
{
	stack_t *temp;

	if (!top)
		return;

	while (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}
