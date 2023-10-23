#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
