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

	temp = *top;
	if (!(*top))
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	free(*top);
	*top = temp;
}
