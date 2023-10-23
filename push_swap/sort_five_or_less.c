#include "push_swap.h"

static void	sort_three(t_info *info)
{
	int	top;
	int	mid;
	int	bottom;

	top = info->stack_a->top->value;
	mid = info->stack_a->top->next->value;
	bottom = info->stack_a->top->next->next->value;
	if (top > mid && top > bottom)
	{
		rotate(info, A);
		if (mid > bottom)
			swap(info, A);
	}
	else if (mid > top && mid > bottom)
	{
		reverse_rotate(info, A);
		if (bottom > top)
			swap(info, A);
	}
	else
	{
		if (top > mid)
			swap(info, A);
	}
}

static void	sort_four_or_five(t_info *info)
{
	int	top;
	int	next;
	int	size[3];
	int	vertices[4];

	push(info, B);
	if (info->total_size == 5)
	{
		push(info, B);
		top = info->stack_b->top->value;
		next = info->stack_b->top->next->value;
		if (top < next)
			swap(info, B);
	}
	sort_three(info);
	size[0] = 0;
	size[1] = info->stack_b->size;
	size[2] = info->stack_a->size;
	while (size[1] + size[2] > 0)
	{
		set_vertices(info, vertices, A);
		get_vertex(size, vertices, ASC);
		push_vertex(info, size, vertices, A);
	}
}

void	sort_five_or_less(t_info *info)
{
	if (info->total_size == 2)
		swap(info, A);
	else if (info->total_size == 3)
		sort_three(info);
	else
		sort_four_or_five(info);
	write_all(info, 0);
	delete_info(&info);
}
