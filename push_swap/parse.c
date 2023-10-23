#include "push_swap.h"

static int	put_integer_to_arr(const char *str, int *array_of_nums, int idx)
{
	unsigned long long	res;
	int					sign;
	int					check;

	res = 0;
	sign = 1;
	check = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		check = 1;
		res = res * 10 + *str++ - '0';
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			return (0);
	}
	if (*str != '\0' || !check)
		return (0);
	array_of_nums[idx] = (int)res * sign;
	return (1);
}

static int	ft_atoi_to_array(char **split_str, int *array_of_nums, int idx)
{
	int	i;
	int	res;

	i = -1;
	while (split_str[++i])
	{
		res = put_integer_to_arr(split_str[i], array_of_nums, idx++);
		if (!res)
		{
			i = -1;
			while (split_str[++i])
				free(split_str[i]);
			free(split_str);
			free(array_of_nums);
			exit_program();
		}
	}
	i = -1;
	while (split_str[++i])
		free(split_str[i]);
	free(split_str);
	return (idx);
}

int	*parse_to_array(int argc, char *argv[], int total_size)
{
	int		idx;
	int		i;
	int		*array_of_nums;
	char	**split_str;

	array_of_nums = (int *)malloc(sizeof(int) * total_size);
	if (!array_of_nums)
		return (NULL);
	idx = 0;
	i = 0;
	while (++i < argc)
	{
		split_str = ft_split_by_white_space(argv[i]);
		if (!split_str)
		{
			free(array_of_nums);
			return (NULL);
		}
		idx = ft_atoi_to_array(split_str, array_of_nums, idx);
	}
	return (array_of_nums);
}
