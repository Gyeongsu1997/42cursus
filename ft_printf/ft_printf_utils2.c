#include "ft_printf.h"

static char	ft_convert_hex(int n, char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n < 10 || c == 'x')
		return (hex[n]);
	else
		return (hex[n] - 32);
}

int	ft_convert_p(unsigned long long ptr)
{
	char	hex;
	int		res;
	int		len;

	len = 0;
	if (ptr >= 16)
		len = ft_convert_p(ptr / 16);
	if (len == -1)
		return (-1);
	hex = ft_convert_hex(ptr % 16, 'x');
	res = write(1, &hex, 1);
	if (res == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_convert_x(unsigned int nbr, char c)
{
	char	hex;
	int		res;
	int		len;

	len = 0;
	if (nbr >= 16)
		len = ft_convert_x(nbr / 16, c);
	if (len == -1)
		return (-1);
	hex = ft_convert_hex(nbr % 16, c);
	res = write(1, &hex, 1);
	if (res == -1)
		return (-1);
	len++;
	return (len);
}
