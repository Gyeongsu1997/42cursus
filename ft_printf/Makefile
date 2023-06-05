CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
HEADER = ft_printf.h
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C Libft all
	cp Libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	make -C Libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
