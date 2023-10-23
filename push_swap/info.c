#include "push_swap.h"

t_triangle	*create_tri(int size, int order, int a_or_b)
{
	t_triangle	*tri;

	tri = (t_triangle *)malloc(sizeof(t_triangle));
	if (!tri)
		return (NULL);
	tri->size = size;
	tri->order = order;
	tri->a_or_b = a_or_b;
	return (tri);
}

t_info	*create_info(int total_size)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->stack_a = create_stack();
	info->stack_b = create_stack();
	if (!(info->stack_a && info->stack_b))
	{
		free(info->stack_a);
		free(info->stack_b);
		free(info);
		return (NULL);
	}
	info->total_size = total_size;
	info->tri_head = NULL;
	info->cmd = NULL;
	return (info);
}

void	delete_info(t_info **info)
{
	delete_stack(&((*info)->stack_a));
	delete_stack(&((*info)->stack_b));
	if ((*info)->tri_head != NULL)
		ft_lstclear(&((*info)->tri_head), free);
	clear_cmd(&((*info)->cmd));
	free(*info);
	*info = NULL;
}
