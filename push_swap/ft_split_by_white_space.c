#include "push_swap.h"

static int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char const *s, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (in_charset(*s, charset))
			s++;
		if (*s != '\0')
			cnt++;
		while (*s && !in_charset(*s, charset))
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

static int	ft_put_arr(char const *s, char *charset, char **arr)
{
	int		idx;
	size_t	i;
	char	*str;

	idx = 0;
	while (*s)
	{
		while (in_charset(*s, charset))
			s++;
		i = 0;
		while (s[i] != '\0' && !in_charset(s[i], charset))
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
		while (*s && !in_charset(*s, charset))
			s++;
	}
	return (1);
}

char	**ft_split_by_white_space(char const *s)
{
	int		res;
	int		cnt;
	char	**arr;
	char	charset[7];

	if (!s)
		return (NULL);
	charset[0] = 9;
	charset[1] = 10;
	charset[2] = 11;
	charset[3] = 12;
	charset[4] = 13;
	charset[5] = 32;
	charset[6] = '\0';
	cnt = ft_count(s, charset);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (NULL);
	res = ft_put_arr(s, charset, arr);
	if (!res)
		return (NULL);
	arr[cnt] = NULL;
	return (arr);
}
