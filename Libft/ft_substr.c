#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	min;
	char	*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start >= len)
		min = len;
	else
		min = s_len - start;
	subs = (char *)malloc(min + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < min)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
