#include "main.h"

/**
 * monty_sub - Subtract the top element from the second top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	monty_pop(stack, line_number);
}
