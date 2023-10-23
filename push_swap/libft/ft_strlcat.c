#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen + dstsize);
	dstlen = ft_strlen(dst);
	if (dstlen > dstsize)
		return (srclen + dstsize);
	dst += dstlen;
	while (*src && dstsize - dstlen > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
