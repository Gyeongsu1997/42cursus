#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./Libft/libft.h"

int	ft_printf(const char *fmt, ...);
int	ft_convert_c(char c);
int	ft_convert_s(char *str);
int	ft_convert_d(int nbr);
int	ft_convert_u(unsigned int nbr);
int	ft_convert_p(unsigned long long ptr);
int	ft_convert_x(unsigned int nbr, char c);

#endif
