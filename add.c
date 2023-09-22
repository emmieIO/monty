#include "monty.h"

/**
 * monty_add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function adds the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 * and exits with EXIT_FAILURE.
 * The result is stored in the second top element of the stack, and the top
 * element is removed, making the stack one element shorter.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{	
	int result;
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	(*stack)->n = result;
}

