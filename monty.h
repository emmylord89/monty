#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 *
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);

char  *clean_line(char *content);
void free_stack(stack_t *head);

int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

void f_myadd(stack_t **head, unsigned int counter);
void f_mysub(stack_t **head, unsigned int counter);
void f_mydiv(stack_t **head, unsigned int counter);
void f_mymul(stack_t **head, unsigned int counter);
void f_mymod(stack_t **head, unsigned int counter);


void f_mypush(stack_t **head, unsigned int number);
void f_mypall(stack_t **head, unsigned int number);
void f_mypint(stack_t **head, unsigned int number);
void f_mypop(stack_t **head, unsigned int counter);
void f_myswap(stack_t **head, unsigned int counter);
void f_mynop(stack_t **head, unsigned int counter);


void f_mypchar(stack_t **head, unsigned int counter);
void f_mypstr(stack_t **head, unsigned int counter);

void f_myrotl(stack_t **head, unsigned int counter);
void f_myrotr(stack_t **head, __attribute__((unused)) unsigned int counter);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_myqueue(stack_t **head, unsigned int counter);
void f_mystack(stack_t **head, unsigned int counter);

#endif
