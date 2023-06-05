#include "ft_printf.h"

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
