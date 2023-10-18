#include "monty.h"

/**
 * pop_element - Removes the top element from the stack.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter (required by function pointer type).
 *
 */
void pop_element(stack_t **top, unsigned int value)
{
	stack_t *temp;
	(void)value;

	if (!(*top))
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	temp = temp->next;
	free(*top);
	*top = temp;
	if (*top)
		(*top)->prev = NULL;
}
/**
 * swap_element - Swaps the top two elements of the stack.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter (required by function pointer type).
 *
 */
void swap_element(stack_t **top, unsigned int value)
{
	stack_t *temp;
	int temp_value;
	(void)value;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*top)->next;
		temp_value = (*top)->n;
		(*top)->n = temp->n;
		temp->n = temp_value;
	}
}
/**
 * nop_element - Does nothing.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter (required by function pointer type).
 */
void nop_element(stack_t **top, unsigned int value)
{
	(void)top;
	(void)value;
}
