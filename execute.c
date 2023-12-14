#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: 0 or 1
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
