#include "monty.h"

/**
* execute - execute opcode
* @stack: stack of linked list
* @counter: line counter
* @file: pointer to monty file stream
* @content: line content
*
* Return: none
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_mypush}, {"pall", f_mypall}, {"pint", f_mypint},
				{"pop", f_mypop},
				{"swap", f_myswap},
				{"add", f_myadd},
				{"nop", f_mynop},
				{"sub", f_mysub},
				{"div", f_mydiv},
				{"mul", f_mymul},
				{"mod", f_mymod},
				{"pchar", f_mypchar},
				{"pstr", f_mypstr},
				{"rotl", f_myrotl},
				{"rotr", f_myrotr},
				{"queue", f_myqueue},
				{"stack", f_mystack},
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
