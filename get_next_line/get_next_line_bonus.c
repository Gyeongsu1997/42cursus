#include "get_next_line_bonus.h"

static t_list	*ft_lstfind(t_list **lst, int fd)
{
	t_list	*node;
	t_list	*prev;

	prev = *lst;
	node = prev->next;
	if (prev->fd == fd)
		return (prev);
	while (node)
	{
		if (node->fd == fd)
			return (node);
		prev = node;
		node = prev->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	prev->next = node;
	node->fd = fd;
	node->save = NULL;
	node->next = NULL;
	return (node);
}

static char	*ft_find_line(t_list **head, t_list **node)
{
	size_t	i;
	char	*line;
	char	*save_old;

	i = 0;
	while (((*node)->save)[i])
	{
		if (((*node)->save)[i] == '\n')
			break ;
		i++;
	}
	if (!((*node)->save)[i])
		return (NULL);
	save_old = (*node)->save;
	line = ft_substr(save_old, 0, i + 1);
	(*node)->save = ft_strdup(&save_old[i + 1]);
	free(save_old);
	if (!line || !((*node)->save))
	{
		free(line);
		ft_free_node(head, node);
		return (NULL);
	}
	return (line);
}

static int	ft_read_line(int fd, t_list **node, char *buf)
{
	int		readbytes;
	char	*save_old;

	if (!buf)
		return (-1);
	readbytes = read(fd, buf, BUFFER_SIZE);
	if (readbytes > 0)
	{
		buf[readbytes] = '\0';
		save_old = (*node)->save;
		(*node)->save = ft_strjoin(save_old, buf);
		free(save_old);
	}
	if (!((*node)->save))
		return (-1);
	return (readbytes);
}

static char	*ft_return_line(int fd, t_list **head, t_list **node)
{
	int		readbytes;
	char	*buf;
	char	*line;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readbytes = 1;
	while (readbytes > 0)
	{
		line = ft_find_line(head, node);
		if (line || !*node)
		{
			free(buf);
			return (line);
		}
		readbytes = ft_read_line(fd, node, buf);
	}
	free(buf);
	if (readbytes == -1 || (readbytes == 0 && !*((*node)->save)))
	{
		ft_free_node(head, node);
		return (NULL);
	}
	line = ft_strdup((*node)->save);
	ft_free_node(head, node);
	return (line);
}

char	*get_next_line(int fd)
{
	t_list			*node;
	static t_list	*head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
			return (NULL);
		node->fd = fd;
		node->save = NULL;
		node->next = NULL;
		head = node;
	}
	else
		node = ft_lstfind(&head, fd);
	if (!node)
		return (NULL);
	if (!node->save)
		node->save = ft_strdup("");
	if (!node->save)
		return (ft_free_node(&head, &node));
	return (ft_return_line(fd, &head, &node));
}
