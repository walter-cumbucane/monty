#include "monty.h"

/**
 *check_arguments -checks whether the user has given a file as an argument
 *@ac: the number of command line arguments
 * Return: Nothing
 */
void check_arguments(int ac)
{
	if (ac != 2)
	{
		write(2, "USAGE: monty file\n", _strlen("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}
}

/**
 *can_i_open -checks whether the filename given can be opened or not
 *@argv: an array containing all the command line arguments
 * Return: Nothing
 */
void can_i_open(char **argv)
{
	if (open(argv[1], O_RDONLY) == -1)
	{
		write(2, "Error: Can't open file <file>\n", _strlen("Error: Can't open file <file>\n"));
		exit(EXIT_FAILURE);
	}
}

/**
 *initialize_content_variable - initializes the node that will handle the file's content
 * Return: Nothing
 */

void initialize_content_variable()
{
	content = malloc(sizeof(file_r));
	if (!content)
	{
		write(2, "Error: malloc failed\n", _strlen("Error: malloc failed\n"));
		exit(EXIT_FAILURE);
	}
	content->fd = NULL;
	content->line = NULL;
	content->num_tokens = 0;
	content->tokens_array = NULL;
	content->line_number = 0;
}

/**
 *read_file - reads the content of the bytecode file line per line
 *@argv: an array containing all command line arguments
 * Return: Nothing
 */

void read_file(char **argv)
{
	FILE *stream;
	size_t status = 0;
	char *line_copy;
	int i = 0;

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		write(2, "Error: Can't open file <file>\n", _strlen("Error: Can't open file <file>\n"));
		exit(EXIT_FAILURE);
	}
	content->fd = stream;
	while (getline(&content->line, &status, content->fd) != -1)
	{
		line_copy = malloc(sizeof(content->line) + 1);
		_strcpy(line_copy, content->line);
		content->num_tokens = count_tokens(line_copy);
		tokenization();
		while (*((content->tokens_array) + i) != NULL)
		{
			printf("%s\n", (*((content->tokens_array) + i)));
			i++;
		}
		break;
	}
}
