#include "push_swap.h"

t_element	*seek_bottom(t_stack *stack)
{
	t_element	*bottom;

	bottom = stack->top;
	if (!bottom)
		return (NULL);
	while (bottom->next)
		bottom = bottom->next;
	return (bottom);
}
