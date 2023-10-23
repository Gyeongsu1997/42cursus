#include "libft.h"

static void	ft_put_digit(char *str, unsigned int nbr, int cnt)
{
	if (nbr >= 10)
		ft_put_digit(str, nbr / 10, cnt - 1);
	str[cnt] = '0' + nbr % 10;
}

char	*ft_itoa(int n)
{
	int				cnt;
	unsigned int	nbr;
	unsigned int	tmp;
	char			*str;

	nbr = n * ((n > 0) - (n < 0));
	tmp = nbr;
	cnt = 1;
	while (tmp >= 10)
	{
		cnt++;
		tmp /= 10;
	}
	if (n < 0)
		cnt++;
	str = (char *)malloc(cnt + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_put_digit(str, nbr, cnt - 1);
	str[cnt] = '\0';
	return (str);
}
