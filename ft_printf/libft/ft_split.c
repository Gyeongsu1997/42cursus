#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

static void	ft_free_arr(char **arr, int idx)
{
	while (idx--)
		free(arr[idx]);
	free(arr);
}

static int	ft_put_arr(char const *s, char c, char **arr)
{
	int		idx;
	size_t	i;
	char	*str;

	idx = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i == 0)
			return (1);
		str = ft_substr(s, 0, i);
		if (!str)
		{
			ft_free_arr(arr, idx);
			return (0);
		}
		arr[idx++] = str;
		while (*s && *s != c)
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		res;
	int		cnt;
	char	**arr;

	if (!s)
		return (NULL);
	cnt = ft_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (NULL);
	res = ft_put_arr(s, c, arr);
	if (!res)
		return (NULL);
	arr[cnt] = NULL;
	return (arr);
}
