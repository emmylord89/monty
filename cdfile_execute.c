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
				{"cdfile_push", cdfun_push}, {"pall", cdfun_pall}, {"pint", cdfun_pint},
				{"cdfile_pop", cdfun_pop},
				{"cdfile_swap", cdfun_swap},
				{"cdfile_add", cdfun_add},
				{"cdfile_nop", cdfun_nop},
				{"cdfile_sub", cdfun_sub},
				{"cdfile_div", cdfun_div},
				{"cdfile_mul", cdfun_mul},
				{"cdfile_mod", cdfun_mod},
				{"cdfile_pchar", cdfun_pchar},
				{"cdfile_pstr", cdfun_pstr},
				{"cdfile_rotl", cdfun_rotl},
				{"cdfile_rotr", cdfun_rotr},
				{"cdfile_queue", cdfun_queue},
				{"cdfile_stack", cdfun_stack},
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
		cdfree_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
