#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	set_the_top(t_info *info, int value)
{
	int			idx;
	int			cnt;
	t_element	*element;

	idx = 0;
	element = info->stack_a->top;
	while (element)
	{
		if (element->value == value)
			break ;
		element = element->next;
		idx++;
	}
	if (idx <= info->stack_a->size / 2)
	{
		cnt = idx;
		while (--cnt >= 0)
			rotate(info, A);
	}
	else
	{
		cnt = info->stack_a->size - idx;
		while (--cnt >= 0)
			reverse_rotate(info, A);
	}
}

static void	push_several(t_info *info, t_triangle *tri)
{
	t_element	*element;
	int			size;
	int			*arr;
	int			i;

	element = info->stack_a->top;
	size = tri->size;
	arr = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		arr[i] = element->value;
		element = element->next;
	}
	bubble_sort(arr, size);
	i = -1;
	while (++i < size)
	{
		if (tri->order == ASC)
			set_the_top(info, arr[size - i - 1]);
		else
			set_the_top(info, arr[i]);
		push(info, B);
	}
	free(arr);
}

static void	push_two(t_info *info, t_triangle *tri)
{
	int	tmp1;
	int	tmp2;

	tmp1 = info->stack_a->top->value;
	tmp2 = info->stack_a->top->next->value;
	if (tri->order == ASC && tmp1 < tmp2)
		swap(info, A);
	else if (tri->order == DESC && tmp1 > tmp2)
		swap(info, A);
	push(info, B);
	push(info, B);
}

void	divide(t_info *info)
{
	t_list		*node;
	t_triangle	*tri;

	node = info->tri_head;
	while (node)
	{
		tri = (t_triangle *)(node->content);
		if (tri->size > 2)
			push_several(info, tri);
		else if (tri->size == 2)
			push_two(info, tri);
		else
			push(info, B);
		node = node->next;
	}
}
