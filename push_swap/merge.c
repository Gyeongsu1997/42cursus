#include "push_swap.h"

static t_triangle	**list_to_array(t_info *info, int size)
{
	int			i;
	t_list		*node;
	t_triangle	**tri_arr;

	tri_arr = (t_triangle **)malloc(sizeof(t_triangle *) * size);
	if (!tri_arr)
	{
		delete_info(&info);
		exit_program();
	}
	node = info->tri_head;
	i = -1;
	while (++i < size)
	{
		tri_arr[i] = (t_triangle *)(node->content);
		node = node->next;
	}
	return (tri_arr);
}

static void	push_one_third(t_info *info, t_triangle **tri_arr, int size)
{
	int			i;
	int			j;
	t_triangle	*tmp;

	i = -1;
	while (++i < (size / 3))
	{
		tmp = tri_arr[size - 1 - i];
		j = -1;
		while (++j < tmp->size)
			push(info, tmp->a_or_b * -1);
		tmp->order *= -1;
		tmp->a_or_b *= -1;
	}
}

static void	merge_three(t_info *info, t_triangle	*tri[3])
{
	int	dst;
	int	order;
	int	size[3];
	int	vertices[4];

	dst = tri[2]->a_or_b;
	order = tri[2]->order;
	size[0] = tri[0]->size;
	size[1] = tri[1]->size;
	size[2] = tri[2]->size;
	while (size[0] + size[1] + size[2] > 0)
	{
		set_vertices(info, vertices, dst);
		get_vertex(size, vertices, order);
		push_vertex(info, size, vertices, dst);
	}
}

static void	reset_triangle(t_info *info, int size)
{
	int		i;
	t_list	*current;
	t_list	*next;

	current = info->tri_head;
	next = current->next;
	i = 0;
	while (++i < (size / 3))
	{
		current = current->next;
		next = current->next;
	}
	current->next = NULL;
	ft_lstclear(&next, free);
}

void	merge(t_info *info)
{
	int			i;
	int			size;
	t_triangle	**tri_arr;
	t_triangle	*tri[3];

	size = ft_lstsize(info->tri_head);
	tri_arr = list_to_array(info, size);
	push_one_third(info, tri_arr, size);
	i = -1;
	while (++i < (size / 3))
	{
		tri[0] = tri_arr[i];
		tri[1] = tri_arr[(size / 3) * 2 - 1 - i];
		tri[2] = tri_arr[size - 1 - i];
		merge_three(info, tri);
		tri[0]->a_or_b *= -1;
		tri[0]->size = tri[0]->size + tri[1]->size + tri[2]->size;
	}
	reset_triangle(info, size);
	free(tri_arr);
}
