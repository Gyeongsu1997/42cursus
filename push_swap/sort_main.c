#include "push_swap.h"

static void	init_stack(t_info *info, int *array_of_nums)
{
	int	i;
	int	total_size;

	total_size = info->total_size;
	i = 0;
	while (i < total_size)
	{
		if (!push_integer(info->stack_a, array_of_nums[total_size - 1 - i]))
		{
			free(array_of_nums);
			delete_info(&info);
			exit_program();
		}
		i++;
	}
}

static int	is_sorted(int *array_of_nums, int total_size)
{
	int	i;
	int	j;
	int	tmp;
	int	is_sorted;

	is_sorted = 1;
	i = -1;
	while (++i < total_size - 1)
	{
		j = -1;
		while (++j < total_size - 1 - i)
		{
			if (array_of_nums[j] > array_of_nums[j + 1])
			{
				tmp = array_of_nums[j];
				array_of_nums[j] = array_of_nums[j + 1];
				array_of_nums[j + 1] = tmp;
				is_sorted = 0;
			}
		}
	}
	if (is_sorted)
		return (1);
	return (0);
}

static void	is_duplicated(t_info *info, int *array_of_nums)
{
	int	i;
	int	total_size;

	i = 0;
	total_size = info->total_size;
	while (i < total_size - 1)
	{
		if (array_of_nums[i] == array_of_nums[i + 1])
		{
			free(array_of_nums);
			delete_info(&info);
			exit_program();
		}
		i++;
	}
}

void	sort_main(t_info *info, int *array_of_nums)
{
	init_stack(info, array_of_nums);
	if (is_sorted(array_of_nums, info->total_size))
	{
		is_duplicated(info, array_of_nums);
		free(array_of_nums);
		delete_info(&info);
		return ;
	}
	is_duplicated(info, array_of_nums);
	free(array_of_nums);
	if (info->total_size <= 5)
		sort_five_or_less(info);
	else
		sort_more_than_five(info);
}
