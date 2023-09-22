#include "monty.h"

/**
 * monty_rotl - Rotates the stack to the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        stack_t *top = *stack;
        stack_t *second = top->next;
        stack_t *temp = *stack;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = top;
        top->prev = temp;
        top->next = NULL;
        *stack = second;
        second->prev = NULL;
    }
}
