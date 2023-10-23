#include "push_swap.h"

int	push_integer(t_stack *stack, int value)
{
	t_element	*new;

	if (!stack)
		return (0);
	new = (t_element *)malloc(sizeof(t_element));
	if (!new)
		return (0);
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
	return (1);
}

int	push_element_to_stack(t_stack *stack, t_element *new)
{
	if (!stack || !new)
		return (0);
	new->next = stack->top;
	stack->top = new;
	stack->size++;
	return (1);
}

t_element	*pop_element_from_stack(t_stack *stack)
{
	t_element	*popped;

	if (!stack || stack->size == 0)
		return (NULL);
	popped = stack->top;
	stack->top = popped->next;
	popped->next = NULL;
	stack->size--;
	return (popped);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

void	delete_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	while ((*stack)->size)
		free(pop_element_from_stack(*stack));
	free(*stack);
	*stack = NULL;
}
