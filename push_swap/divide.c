#include "push_swap.h"

static int	check_create(t_triangle *tri, t_list *new, t_list **append)
{
	if (!tri || !new)
	{
		free(tri);
		free(new);
		ft_lstclear(append, free);
		return (0);
	}
	else
		return (1);
}

static void	insert_tri(t_info *info, t_triangle *tmp, t_list **append)
{
	int			size;
	t_triangle	*tri;
	t_list		*new;

	size = tmp->size;
	tri = create_tri(size / 3 + size % 3, tmp->order * -1, tmp->a_or_b * -1);
	new = ft_lstnew(tri);
	if (!check_create(tri, new, append))
	{
		delete_info(&info);
		exit_program();
	}
	ft_lstadd_front(append, new);
}

void	divide_tri_1(t_info *info)
{
	t_list		*node;
	t_list		*append;
	t_triangle	*tmp;

	node = info->tri_head;
	append = NULL;
	while (node)
	{
		tmp = (t_triangle *)(node->content);
		insert_tri(info, tmp, &append);
		tmp->size /= 3;
		tmp->a_or_b *= -1;
		node = node->next;
	}
	ft_lstlast(info->tri_head)->next = append;
}

void	divide_tri_2(t_info *info, int size)
{
	int			i;
	t_list		*node;
	t_list		*append;
	t_list		*new;
	t_triangle	*tri;

	i = -1;
	node = info->tri_head;
	append = NULL;
	while (++i < size)
	{
		tri = (t_triangle *)(node->content);
		tri = create_tri(tri->size, tri->order * -1, tri->a_or_b);
		new = ft_lstnew(tri);
		if (!check_create(tri, new, &append))
		{
			delete_info(&info);
			exit_program();
		}
		ft_lstadd_front(&append, new);
		node = node->next;
	}
	ft_lstlast(info->tri_head)->next = append;
}

int	get_depth(int size)
{
	int	depth;

	depth = 0;
	while (size > 5)
	{
		size /= 3;
		depth++;
	}
	return (depth);
}
