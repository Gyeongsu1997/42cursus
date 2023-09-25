#include "get_next_line.h"

static void	free_ptr(void **ptr)
{
	if (*ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static char	*ft_find_line(char **p_save)
{
	size_t	i;
	char	*line;
	char	*save_old;

	i = 0;
	while ((*p_save)[i])
	{
		if ((*p_save)[i] == '\n')
			break ;
		i++;
	}
	if (!(*p_save)[i])
		return (NULL);
	save_old = *p_save;
	line = ft_substr(save_old, 0, i + 1);
	*p_save = ft_strdup(&save_old[i + 1]);
	free(save_old);
	if (!line || !*p_save)
	{
		free(line);
		free_ptr((void **)p_save);
		return (NULL);
	}
	return (line);
}

static int	ft_read_line(int fd, char **p_save, char *buf)
{
	int		readbytes;
	char	*save_old;

	if (!buf)
		return (-1);
	readbytes = read(fd, buf, BUFFER_SIZE);
	if (readbytes > 0)
	{
		buf[readbytes] = '\0';
		save_old = *p_save;
		*p_save = ft_strjoin(save_old, buf);
		free(save_old);
	}
	if (!*p_save)
		return (-1);
	return (readbytes);
}

static char	*ft_return_line(int fd, char **p_save)
{
	int		readbytes;
	char	*line;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readbytes = 1;
	while (readbytes > 0)
	{
		line = ft_find_line(p_save);
		if (line || !*p_save)
		{
			free(buf);
			return (line);
		}
		readbytes = ft_read_line(fd, p_save, buf);
	}
	free(buf);
	if (readbytes == -1 || (readbytes == 0 && !**p_save))
	{
		free_ptr((void **)p_save);
		return (NULL);
	}
	line = ft_strdup(*p_save);
	free_ptr((void **)p_save);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	return (ft_return_line(fd, &save));
}
