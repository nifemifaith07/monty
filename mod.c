#include "monty.h"

/**
 * s_mod - computes the rest of the division of the second top element of
 *	stack by the top element of the stack.
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void s_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mod = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->next->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			free(global.content);
			fclose(global.file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		mod = temp->next->n % temp->n;
		temp->next->n = mod;
		*stack = temp->next;
		free(temp);
		if (*stack)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
