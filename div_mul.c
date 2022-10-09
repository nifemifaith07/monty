#include "monty.h"

/**
 * s_div - divides second top element of the stack
 *	by the top element of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void s_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int div = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			free(global.content);
			fclose(global.file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		div = temp->next->n / temp->n;
		temp->next->n = div;
		*stack = temp->next;
		free(temp);
		if (*stack)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * s_mul - multiplies second top element of the stack
 *	by the top element of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void s_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mul = 0;

	if (*stack && (*stack)->next)
	{
		mul = temp->next->n * temp->n;
		temp->next->n = mul;
		*stack = temp->next;
		free(temp);
		if (*stack)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
