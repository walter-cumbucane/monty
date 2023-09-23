#include "monty.h"

/* Initializing the global variable */
file_r *content = NULL;
/**
 * main - an interpreter for monty bytecodes
 * @ac : argument counter
 * @argv : array of all arguments as strings
 *
 * Return: Always zero on success, else exits on execution errro
*/

int main(int ac, char **argv)
{
	check_arguments(ac);
	can_i_open(argv);
	initialize_content_variable();
	read_file(argv);
	return (EXIT_SUCCESS);
}
