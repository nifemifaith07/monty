#include "monty.h"
/**
 * s_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to head
 * @line_number: current line
 */
void s_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 128 || temp->n < 0)
	{
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * s_pstr - prints the string starting at the top of the stack
 * @stack: pointer to head
 * @line_number: current line
 */
void s_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (line_number)
		while ((temp && temp->n != 0) && (temp->n > 0 && temp->n < 128))
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
	printf("\n");
}
