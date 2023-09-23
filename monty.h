#ifndef MONTY_H
#define MONTY_H

/*Header files declaration */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/* Structure definitions */
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
 * struct file_read - to read the bytecode files
 * @fd : a pointer to the bytecode file give as an argument
 * @line: a buffer where each line of the file will be stored
 *
 * Description: to read the content from the bytecode files given as arguments
 */
typedef struct file_read
{
	FILE *fd;
	char *line;
} file_r;

/* Global file variable */
extern file_r *content;

/* String handling functions */
int _strlen(char *s);


/*Program functions */
void check_arguments(int ac);
void can_i_open(char **argv);
void initialize_content_variable();
void read_file(char **argv);

#endif
