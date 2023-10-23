#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current->next)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	del(current->content);
	free(current);
	*lst = NULL;
}
