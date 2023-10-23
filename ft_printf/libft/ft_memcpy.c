#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (NULL);
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (n > 0)
	{
		*dst2++ = *src2++;
		n--;
	}
	return (dst);
}
