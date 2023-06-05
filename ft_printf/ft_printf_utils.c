#include "ft_printf.h"

int	ft_convert_c(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_convert_s(char *str)
{
	int		len;
	char	*str2;

	if (!str)
		str2 = "(null)";
	else
		str2 = str;
	len = write(1, str2, ft_strlen(str2));
	return (len);
}

int	ft_convert_d(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_convert_u(unsigned int nbr)
{
	char	digit;
	int		res;
	int		len;

	len = 0;
	if (nbr >= 10)
		len = ft_convert_u(nbr / 10);
	if (len == -1)
		return (-1);
	digit = nbr % 10 + '0';
	res = write(1, &digit, 1);
	if (res == -1)
		return (-1);
	len++;
	return (len);
}
