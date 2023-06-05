#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (NULL);
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (dst2 <= src2)
	{
		while (len--)
			*dst2++ = *src2++;
	}
	else
	{
		dst2 += len - 1;
		src2 += len - 1;
		while (len--)
			*dst2-- = *src2--;
	}
	return (dst);
}
