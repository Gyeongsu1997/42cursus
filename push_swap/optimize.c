#include "push_swap.h"

static int	is_combinable(t_info *info, t_element **new, int type1, int type2)
{
	int	type;

	if ((type1 == SA && type2 == SB) || (type1 == SB && type2 == SA))
		type = SS;
	else if ((type1 == RA && type2 == RB) || (type1 == RB && type2 == RA))
		type = RR;
	else if ((type1 == RRA && type2 == RRB) || (type1 == RRB && type2 == RRA))
		type = RRR;
	else
		return (0);
	append_cmd(info, new, type);
	return (1);
}

static int	is_erasable(int type1, int type2)
{
	if (type1 == RRA && type2 == RA)
		return (1);
	else if (type1 == RA && type2 == RRA)
		return (1);
	else if (type1 == RRB && type2 == RB)
		return (1);
	else if (type1 == RB && type2 == RRB)
		return (1);
	else if (type1 == PA && type2 == PB)
		return (1);
	else if (type1 == PB && type2 == PA)
		return (1);
	else
		return (0);
}

t_element	*optimize(t_info *info)
{
	int			type1;
	int			type2;
	t_element	*node;
	t_element	*new;

	new = NULL;
	node = info->cmd;
	while (node)
	{
		if (node->next == NULL)
		{
			append_cmd(info, &new, node->value);
			return (new);
		}
		type1 = node->value;
		type2 = node->next->value;
		if (is_combinable(info, &new, type1, type2))
			node = node->next;
		else if (is_erasable(type1, type2))
			node = node->next;
		else
			append_cmd(info, &new, type1);
		node = node->next;
	}
	return (new);
}
