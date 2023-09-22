#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Description:
 * This function reads and interprets Monty byte code from a file.
 * It processes each line of the file, executes the corresponding Monty
 * instruction, and handles errors as specified in the Monty language
 * specification.
 *
 * Return: Always 0 on success, EXIT_FAILURE on error.
 */
#define MAX_LINE_LENGTH 1024
int main(int argc, char *argv[]) {
    FILE *file;
    stack_t *stack = NULL;  /* Initialize an empty stack */
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    char *opcode;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        opcode = strtok(line, " \t\n");
	if (line[0] == '#') {
            continue;
        }

	if (opcode == NULL) {
            continue;
        }
        execute_instruction(opcode, &stack, line_number);
    }

    free_stack(stack);
    fclose(file);
    return 0;
}
