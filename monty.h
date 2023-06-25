#ifndef MONTY_H
#define MONTY_H
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct buss_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct buss_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  buss_t;
extern buss_t buss;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void my_stack(stack_t **head, unsigned int counter);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
int exe(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
void my_div(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
#endif

