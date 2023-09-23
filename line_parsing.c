#include "monty.h"

/**
 * count_tokens - counts the number of tokens of the read line
 * @line_copy: a copy of the line read from the input
 * @line : the line prompted by the user
 * Return: the number of tokens of the read string
 */


int count_tokens(char *line_copy)
{
	int count = 0;
	char *token = NULL;

	token = strtok(line_copy, " \n");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	if (count == 0)
	{
		free(line_copy);
		return (-1);
	}
	free(token);
	return (count);
}

/**
 * tokenization - set the integer to 402
 * @args: a pointer the integer we want to set to 98
 * @line : the line read from input
 * Return: nothing
 */


void tokenization()
{
	char *token = NULL;
	int num, i;

	num = content->num_tokens;
	content->tokens_array = malloc(sizeof(char *) * (num + 1));
	token = strtok(content->line, " \n");
	for (i = 0; token != NULL; i++)
	{
		*((content->tokens_array) + i) = malloc((sizeof(char) * _strlen(token)) + 1);
		_strcpy(*((content->tokens_array) + i) , token);
		token = strtok(NULL, " \n");
	}
	free(token);
	*((content->tokens_array) + i) = NULL;
}
