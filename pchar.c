#include "monty.h"

/**
 * monty_pchar - Print the character at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;
	stack_t *temp = *stack;
	

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');

	/* Pop the top element*/
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
