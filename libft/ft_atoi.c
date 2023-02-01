#include "libft.h"

static int	ft_escape(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	while ((ft_escape(*nptr)))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while ((ft_isdigit(*nptr)))
	{
		num *= 10;
		num += sign * (*nptr - '0');
		nptr++;
	}
	return (num);
}
