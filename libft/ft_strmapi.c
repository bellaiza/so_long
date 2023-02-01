
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
