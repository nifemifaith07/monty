#include "monty.h"

/**
 * s_swap - swaps the top two elements of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void s_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		if (temp == NULL)
		{
			exit(0);
		}
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		temp->next = *stack;
		temp->prev = NULL;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * s_add - adds the top two elements of the stack.
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void s_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1;
	stack_t *temp2;
	int sum = 0;

	if (*stack && (*stack)->next)
	{
		temp2 = (*stack)->next;
		sum = (*stack)->n + temp2->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
