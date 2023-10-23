#include "push_swap.h"

void	append_cmd(t_info *info, t_element **lst, int type)
{
	t_element	*node;
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	if (!new)
	{
		delete_info(&info);
		exit_program();
	}
	new->value = type;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

void	clear_cmd(t_element **cmd)
{
	t_element	*current;
	t_element	*next;

	if (!cmd || !*cmd)
		return ;
	current = *cmd;
	while (current->next)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	*cmd = NULL;
}

static int	get_num_of_element(t_element *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

static void	write_cmd(int type)
{
	if (type == PA)
		write(1, "pa\n", 3);
	else if (type == PB)
		write(1, "pb\n", 3);
	else if (type == SA)
		write(1, "sa\n", 3);
	else if (type == SB)
		write(1, "sb\n", 3);
	else if (type == RA)
		write(1, "ra\n", 3);
	else if (type == RB)
		write(1, "rb\n", 3);
	else if (type == RRA)
		write(1, "rra\n", 4);
	else if (type == RRB)
		write(1, "rrb\n", 4);
	else if (type == SS)
		write(1, "ss\n", 3);
	else if (type == RR)
		write(1, "rr\n", 3);
	else if (type == RRR)
		write(1, "rrr\n", 4);
}

void	write_all(t_info *info, int option)
{
	t_element	*current;
	t_element	*new;

	if (option == 1)
	{
		new = optimize(info);
		while (get_num_of_element(info->cmd) != get_num_of_element(new))
		{
			clear_cmd(&(info->cmd));
			info->cmd = new;
			new = optimize(info);
		}
		clear_cmd(&new);
	}
	current = info->cmd;
	while (current)
	{
		write_cmd(current->value);
		current = current->next;
	}
}
