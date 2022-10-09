#include "monty.h"

/**
 * s_nop - does nothing
 * @stack: pointer to head/top
 * @line_number: current line number
 * Return: nothing
 */

void s_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * s_sub - subtract top element of stack from second top element of stack.
 * @stack: pointer to head/top
 * @line_number: current line number
 * Return: nothing
 */
void s_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2;
	stack_t *temp1;
	int diff = 0;

	if (*stack && (*stack)->next)
	{
		temp2 = (*stack)->next;
		diff = temp2->n - (*stack)->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = diff;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
