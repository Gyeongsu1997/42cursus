#include "push_swap.h"

void	set_vertices(t_info *info, int *vertices, int dst)
{
	if (dst == A)
	{
		if (seek_bottom(info->stack_b) != NULL)
			vertices[0] = seek_bottom(info->stack_b)->value;
		if (info->stack_b->top != NULL)
			vertices[1] = info->stack_b->top->value;
		if (seek_bottom(info->stack_a) != NULL)
			vertices[2] = seek_bottom(info->stack_a)->value;
	}
	else
	{
		if (seek_bottom(info->stack_a) != NULL)
			vertices[0] = seek_bottom(info->stack_a)->value;
		if (info->stack_a->top != NULL)
			vertices[1] = info->stack_a->top->value;
		if (seek_bottom(info->stack_b) != NULL)
			vertices[2] = seek_bottom(info->stack_b)->value;
	}
}

static int	get_vertex_of_three(int *vertices, int order)
{
	int	i;
	int	max_idx;
	int	min_idx;

	max_idx = 0;
	min_idx = 0;
	i = 0;
	while (++i < 3)
	{
		if (vertices[i] > vertices[max_idx])
			max_idx = i;
		if (vertices[i] < vertices[min_idx])
			min_idx = i;
	}
	if (order == ASC)
		return (vertices[max_idx]);
	else
		return (vertices[min_idx]);
}

static int	get_vertex_of_two(int v1, int v2, int order)
{
	if ((order == ASC && v1 < v2) || (order == DESC && v1 > v2))
		return (v2);
	else
		return (v1);
}

void	get_vertex(int *size, int *vertices, int order)
{
	if (size[0] > 0 && size[1] > 0 && size[2] > 0)
		vertices[3] = get_vertex_of_three(vertices, order);
	else if (size[0] == 0 && size[1] > 0 && size[2] > 0)
		vertices[3] = get_vertex_of_two(vertices[1], vertices[2], order);
	else if (size[0] > 0 && size[1] == 0 && size[2] > 0)
		vertices[3] = get_vertex_of_two(vertices[0], vertices[2], order);
	else if (size[0] > 0 && size[1] > 0 && size[2] == 0)
		vertices[3] = get_vertex_of_two(vertices[0], vertices[1], order);
	else if (size[0] > 0 && size[1] == 0 && size[2] == 0)
		vertices[3] = vertices[0];
	else if (size[0] == 0 && size[1] > 0 && size[2] == 0)
		vertices[3] = vertices[1];
	else
		vertices[3] = vertices[2];
}

void	push_vertex(t_info *info, int *size, int *vertices, int dst)
{
	if (size[0] > 0 && vertices[0] == vertices[3])
	{
		reverse_rotate(info, dst * -1);
		push(info, dst);
		size[0] -= 1;
	}
	else if (size[1] > 0 && vertices[1] == vertices[3])
	{
		push(info, dst);
		size[1] -= 1;
	}
	else if (size[2] > 0 && vertices[2] == vertices[3])
	{
		reverse_rotate(info, dst);
		size[2] -= 1;
	}
}
