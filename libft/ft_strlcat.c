#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (n <= ft_strlen(dst))
		return (n + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while ((src[j] != '\0') && (i + 1 < n))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
