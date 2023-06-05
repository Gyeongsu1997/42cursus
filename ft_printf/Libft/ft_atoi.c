#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	long_max;
	unsigned long long	res;
	int					sign;

	long_max = 9223372036854775807L;
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str++ - 48;
		if (sign == 1 && res > long_max)
			return (-1);
		if (sign == -1 && res > long_max + 1)
			return (0);
	}
	return (sign * res);
}
