#include "monty.h"

/**
 * monty_swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function swaps the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 * and exits with EXIT_FAILURE.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
