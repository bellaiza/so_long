#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (!dest && !source)
		return (NULL);
	while (i < n)
	{
		dest[i] = source[i];
		if ((unsigned char)c == source[i])
		{
			dst = dest;
			return (dst + i + 1);
		}
		i++;
	}
	dst = dest;
	return (NULL);
}
