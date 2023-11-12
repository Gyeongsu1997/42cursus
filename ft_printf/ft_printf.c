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

static int	ft_convert_p(unsigned long long ptr)
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

static int	ft_convert_x(unsigned int nbr, char c)
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

static int	ft_convert(char c, va_list *app)
{
	int	len;

	if (c == 'c')
		len = ft_convert_c(va_arg(*app, int));
	else if (c == 's')
		len = ft_convert_s(va_arg(*app, char *));
	else if (c == 'p')
	{
		len = write(1, "0x", 2);
		if (len == -1)
			return (-1);
		len += ft_convert_p(va_arg(*app, unsigned long long));
	}
	else if (c == 'd' || c == 'i')
		len = ft_convert_d(va_arg(*app, int));
	else if (c == 'u')
		len = ft_convert_u(va_arg(*app, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_convert_x(va_arg(*app, unsigned int), c);
	else if (c == '%')
		len = ft_convert_c('%');
	else
		return (0);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		bytes;
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			bytes = ft_convert(*(++fmt), &ap);
		else
			bytes = write(1, fmt, 1);
		if (bytes == -1)
			return (-1);
		len += bytes;
		fmt++;
	}
	va_end(ap);
	return (len);
}
