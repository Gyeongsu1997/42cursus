#include "push_swap.h"

void	exit_program(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	get_size(char *const str, int idx)
{
	int	size;

	size = 0;
	while (str[idx])
	{
		while (is_white_space(str[idx]))
			idx++;
		if (str[idx] != '\0')
			size++;
		while (str[idx] != '\0' && !is_white_space(str[idx]))
			idx++;
	}
	return (size);
}

static int	get_total_size(int argc, char *argv[])
{
	int	i;
	int	j;
	int	total_size;

	total_size = 0;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_white_space(argv[i][j]))
				j++;
			else
				break ;
		}
		if (argv[i][j] == '\0')
			return (0);
		total_size += get_size(argv[i], j);
	}
	return (total_size);
}

int	main(int argc, char *argv[])
{
	t_info	*info;
	int		total_size;
	int		*array_of_nums;

	if (argc < 2)
		return (1);
	total_size = get_total_size(argc, argv);
	if (!total_size)
		exit_program();
	array_of_nums = parse_to_array(argc, argv, total_size);
	if (!array_of_nums)
		exit_program();
	if (total_size == 1)
	{
		free(array_of_nums);
		return (1);
	}
	info = create_info(total_size);
	if (!info)
	{
		free(array_of_nums);
		exit_program();
	}
	sort_main(info, array_of_nums);
	return (0);
}
