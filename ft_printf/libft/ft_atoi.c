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
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		if (sign == 1 && res > long_max)
			return (-1);
		if (sign == -1 && res > long_max + 1)
			return (0);
	}
	return (sign * res);
}
