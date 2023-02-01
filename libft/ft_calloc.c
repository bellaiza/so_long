#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	memory;
	void	*dst;

	memory = size * count;
	dst = malloc(memory);
	if (!(dst))
		return (0);
	ft_memset(dst, 0, memory);
	return (dst);
}
