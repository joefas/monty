#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

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
 * struct tap_s - variables, characters, pointers and application
 * @lifi: flag used to indicate change of stack to queue or vice versa
 * @content: pointer to a content of a line
 * @arg: pointer to an argument
 * @file: pointer to a FILE
 * Description: A program that processes monty file input 
 * and uses data structure to switch between them.
 */
typedef struct tap_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} tap_t;
extern tap_t tap;

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

void free_stack(stack_t *head);
void f_queue(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
void addnode(stack_t **head, int n);
void f_stack(stack_t **head, unsigned int counter);
void f_print(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_push(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void f_pop(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
#endif

