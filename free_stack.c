#include "main.h"
/**
 * free_stack - Frees the memory used by a stack.
 * @stack: A pointer to the head of the stack.
 *
 * Description:
 * This function frees the memory allocated for each element in the stack
 * and the stack itself. It iterates through the stack, freeing each node,
 * until the entire stack is deallocated.
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *current = stack;
		stack = stack->next;
		free(current);
	}
}

