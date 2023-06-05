#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i + needle_len <= len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j])
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
			}
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
