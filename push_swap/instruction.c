#include "push_swap.h"

void	push(t_info *info, int a_or_b)
{
	t_element	*tmp;
	t_stack		*dst;
	t_stack		*src;

	if (a_or_b == A)
	{
		append_cmd(info, &(info->cmd), PA);
		dst = info->stack_a;
		src = info->stack_b;
	}
	else
	{
		append_cmd(info, &(info->cmd), PB);
		dst = info->stack_b;
		src = info->stack_a;
	}
	tmp = pop_element_from_stack(src);
	if (tmp != NULL)
		push_element_to_stack(dst, tmp);
}

void	swap(t_info *info, int a_or_b)
{
	t_element	*tmp1;
	t_element	*tmp2;
	t_stack		*stack;

	if (a_or_b == A)
	{
		append_cmd(info, &(info->cmd), SA);
		stack = info->stack_a;
	}
	else
	{
		append_cmd(info, &(info->cmd), SB);
		stack = info->stack_b;
	}
	if (stack->size < 2)
		return ;
	tmp1 = pop_element_from_stack(stack);
	tmp2 = pop_element_from_stack(stack);
	push_element_to_stack(stack, tmp1);
	push_element_to_stack(stack, tmp2);
}

void	swap_both(t_info *info)
{
	swap(info, A);
	swap(info, B);
}
