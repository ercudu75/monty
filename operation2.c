#include "monty.h"

/**
 * op_div - Divides the second top element of the
 * stack by the top element.
 * @top: Double pointer to the top of the stack.
 * @value: The value to be divided (not used).
 *
 */
void op_div(stack_t **top, unsigned int value)
{
	stack_t *temp;
	(void)value;

	if (!(*top) || !(*top)->next)
	{
		free_stack(*top);
		fprintf(stderr, "L%d: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n = temp->n / (*top)->n;
	(*top) = temp;
	free(temp->prev);
	temp->prev = NULL;
}


