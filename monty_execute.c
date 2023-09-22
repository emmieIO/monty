#include "main.h"
/**
 * execute_instruction - Execute a Monty instruction based on the opcode.
 * @opcode: The opcode of the instruction to execute.
 * @stack: A pointer to the stack to operate on.
 * @line_number: The current line number in the Monty byte code file.
 *
 * Description:
 * This function searches for the opcode in the `monty_instructions` array
 * and executes the associated function. If the opcode is not found, it
 * prints an error message and exits with EXIT_FAILURE.
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t monty_instructions[] ={
	{"push", monty_push},
	{"pall", monty_pall},
	{"pint", monty_pint},
	{"pop", monty_pop},
	{"swap", monty_swap},
	{"add", monty_add},
	{"nop", monty_nop},
	{"sub", monty_sub},
	{"div",monty_div},
	{"mul", monty_mul},
	{"mod", monty_mod},
	{"pchar", monty_pchar},
	{"", monty_rotl},
	{NULL, NULL}
	};

	while (monty_instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, monty_instructions[i].opcode) == 0)
		{
			monty_instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
