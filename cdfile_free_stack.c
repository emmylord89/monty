#include "monty.h"
/**
* cdfree_stack - frees a doubly linked list
* @head: head of the stack
*/
void cdfree_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
