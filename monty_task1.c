#include "main.h"
/**
 * monty_push - Pushes an integer onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function pushes an integer onto the stack. It checks if the argument
 * is a valid integer and handles error cases as specified in the Monty
 * language specification.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int i = 0, value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!arg || !*arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (arg[i])
	{
		if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-' && isdigit(arg[i + 1])))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	value = atoi(arg);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}


/**
 * monty_pall - Prints all values on the stack, starting from the top.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function prints all values on the stack, starting from the top.
 * If the stack is empty, it does not print anything.
 */
void monty_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * monty_pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function prints the value at the top of the stack, followed by a new line.
 * If the stack is empty, it prints an error message and exits with EXIT_FAILURE.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

#include "main.h"

/**
 * monty_pop - Removes the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 *
 * Description:
 * This function removes the top element of the stack.
 * If the stack is empty, it prints an error message and exits with EXIT_FAILURE.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = top->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(top);
}
