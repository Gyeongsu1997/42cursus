CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
HEADER = push_swap.h
SRCS = cmd_utils.c divide.c divide2.c ft_split_by_white_space.c info.c instruction.c \
	   instruction2.c main.c merge.c merge2.c optimize.c parse.c sort_five_or_less.c \
	   sort_main.c sort_more_than_five.c stack_utils.c stack_utils2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft bonus
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	make -C libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
