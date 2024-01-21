#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"file_push", fun_push}, {"pall", fun_pall}, {"pint", fun_pint},
				{"file_pop", fun_pop},
				{"file_swap", fun_swap},
				{"file_add", fun_add},
				{"file_nop", fun_nop},
				{"file_sub", fun_sub},
				{"file_div", fun_div},
				{"file_mul", fun_mul},
				{"file_mod", fun_mod},
				{"file_pchar", fun_pchar},
				{"file_pstr", fun_pstr},
				{"file_rotl", fun_rotl},
				{"file_rotr", fun_rotr},
				{"file_queue", fun_queue},
				{"file_stack", fun_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
