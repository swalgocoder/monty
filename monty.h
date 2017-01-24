#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
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
 * struct instruction_s - opcoode and its function
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


extern int my_array[];
ssize_t getline (char **_lineptr, size_t *_linesize, FILE *_stream);

void cmd_str(char *line, size_t length, FILE *fd);

void argc_check(int argc);
void file_check(FILE *fd, char *infile);

void my_push(stack_t **head_ref, unsigned int line_number);
void my_pall(stack_t **head_ref, unsigned int line_number);

void my_pint(stack_t **head_ref, unsigned int line_number);
void my_pop(stack_t **head_ref, unsigned int line_number);

void my_swap(stack_t **head_ref, unsigned int line_number);
void my_add(stack_t **head_ref, unsigned int line_number);

void my_nop(stack_t **head_ref, unsigned int line_number);


stack_t *addnode_2_end(stack_t **head_ref, const int n);
stack_t *add_mynode(stack_t **head_ref, const int n);
stack_t *find_stk_end(stack_t **head_ref);
char *read_cmd(char *line, unsigned int line_num);
#endif
