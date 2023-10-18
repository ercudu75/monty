#include "monty.h"


void push_element(stack_t **top, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

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
