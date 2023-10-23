#include "push_swap.h"

void	rotate(t_info *info, int a_or_b)
{
	t_element	*top;
	t_element	*bottom;
	t_stack		*stack;

	if (a_or_b == A)
	{
		append_cmd(info, &(info->cmd), RA);
		stack = info->stack_a;
	}
	else
	{
		append_cmd(info, &(info->cmd), RB);
		stack = info->stack_b;
	}
	if (stack->size < 2)
		return ;
	top = pop_element_from_stack(stack);
	bottom = seek_bottom(stack);
	bottom->next = top;
	stack->size++;
}

void	rotate_both(t_info *info)
{
	rotate(info, A);
	rotate(info, B);
}

void	reverse_rotate(t_info *info, int a_or_b)
{
	t_element	*new_bottom;
	t_element	*bottom;
	t_stack		*stack;

	if (a_or_b == A)
	{
		append_cmd(info, &(info->cmd), RRA);
		stack = info->stack_a;
	}
	else
	{
		append_cmd(info, &(info->cmd), RRB);
		stack = info->stack_b;
	}
	if (stack->size < 2)
		return ;
	new_bottom = stack->top;
	while (new_bottom->next->next)
		new_bottom = new_bottom->next;
	bottom = new_bottom->next;
	new_bottom->next = NULL;
	stack->size--;
	push_element_to_stack(stack, bottom);
}

void	reverse_rotate_both(t_info *info)
{
	reverse_rotate(info, A);
	reverse_rotate(info, B);
}
