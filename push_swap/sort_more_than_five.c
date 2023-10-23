#include "push_swap.h"

static void	init_triangle(t_info *info, int size)
{
	t_triangle	*tri;
	t_list		*new;

	if (get_depth(size) % 2 == 1)
		tri = create_tri(size, ASC, A);
	else
		tri = create_tri(size, DESC, B);
	new = ft_lstnew(tri);
	if (!tri || !new)
	{
		free(tri);
		free(new);
		delete_info(&info);
		exit_program();
	}
	ft_lstadd_back(&(info->tri_head), new);
	while (((t_triangle *)(info->tri_head->content))->size > 5)
	{
		size = ft_lstsize(info->tri_head);
		divide_tri_1(info);
		divide_tri_2(info, size);
	}
}

void	sort_more_than_five(t_info *info)
{
	init_triangle(info, info->total_size);
	divide(info);
	while (((t_triangle *)(info->tri_head->content))->size < info->total_size)
		merge(info);
	if (info->stack_a->size == 0)
		while (info->stack_a->size < info->total_size)
			push(info, A);
	write_all(info, 1);
	delete_info(&info);
}
