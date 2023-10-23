#include "libft.h"

static void	ft_print_digit(unsigned int nbr, int fd)
{
	char	digit;

	if (nbr >= 10)
		ft_print_digit(nbr / 10, fd);
	digit = '0' + nbr % 10;
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = n * ((n > 0) - (n < 0));
	if (n < 0)
		write(fd, "-", 1);
	ft_print_digit(nbr, fd);
}
