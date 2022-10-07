#include "monty.h"

/**
 * add_null - remove newline and add null byte
 * @line: line to read
 * Return: line
 */
char add_null(char *line)
{
	int len = line_len(line);

	line[len - 1] = '\0';
	return (*line);
}

/**
 * line_len - length of the line
 * @line: line to read
 * Return: line
 */
int line_len(char *line)
{
	unsigned int count = 0;

	while (line[count])
	{
		count++;
	}
	return (count);
}
