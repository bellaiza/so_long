#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*memory;
	unsigned char	value;

	memory = s;
	value = c;
	i = 0;
	while (i < n)
	{
		memory[i] = value;
		i++;
	}
	s = memory;
	return (s);
}
