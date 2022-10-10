#include "monty.h"
/**
 * s_rotl - rotates the stack to the top.
 * @stack: pointer to head
 * @line_number: current number line
 */

void s_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1;
	stack_t *temp2;

	if (*stack && (*stack)->next)
	{
		temp1 = *stack;
		temp2 = temp1;
		*stack = temp1->next;
		(*stack)->prev = NULL;
		if (line_number)
			while (temp2->next)
			{
				temp2 = temp2->next;
			}
		temp2->next = temp1;
		temp1->prev = temp2;
		temp1->next = NULL;
	}
}

/**
 * s_rotr - rotates the stack to the bottom
 * @stack: pointer to head
 * @line_number: current num line
 */

void s_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2;

	if (*stack && (*stack)->next)
	{
		temp2 = *stack;
		if (line_number)
			while (temp2->next)
			{
				temp2 = temp2->next;
			}
		temp2->next = *stack;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		*stack = temp2;
	}
}
