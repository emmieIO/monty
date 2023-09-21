#include "main.h"

/**
 * monty_nop - Doesn't do anything.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function is a no-op (doesn't do anything).
 * It is used to represent the "nop" opcode.
 * It takes no action and simply returns without any effect on the stack.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
