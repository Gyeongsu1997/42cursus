#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define SA 0
# define SB	1
# define SS	2
# define PA	3
# define PB	4
# define RA	5
# define RB	6
# define RR	7
# define RRA 8
# define RRB 9
# define RRR 10

# define A 1
# define B -1

# define ASC 1
# define DESC -1

typedef struct s_element {
	int					value;
	struct s_element	*next;
}	t_element;

typedef struct s_stack {
	int			size;
	t_element	*top;
}	t_stack;

typedef struct s_triangle {
	int	size;
	int	order;
	int	a_or_b;
}	t_triangle;

typedef struct s_info {
	int			total_size;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list		*tri_head;
	t_element	*cmd;
}	t_info;

void		append_cmd(t_info *info, t_element **lst, int type);
void		clear_cmd(t_element **cmd);
void		write_all(t_info *info, int option);
void		divide_tri_1(t_info *info);
void		divide_tri_2(t_info *info, int size);
int			get_depth(int size);
void		divide(t_info *info);
char		**ft_split_by_white_space(char const *s);
t_triangle	*create_tri(int size, int order, int a_or_b);
t_info		*create_info(int total_size);
void		delete_info(t_info **info);
void		push(t_info *info, int a_or_b);
void		swap(t_info *info, int a_or_b);
void		swap_both(t_info *info);
void		rotate(t_info *info, int a_or_b);
void		rotate_both(t_info *info);
void		reverse_rotate(t_info *info, int a_or_b);
void		reverse_rotate_both(t_info *info);
void		exit_program(void);
void		merge(t_info *info);
void		set_vertices(t_info *info, int *vertices, int dst);
void		get_vertex(int *size, int *vertices, int order);
void		push_vertex(t_info *info, int *size, int *vertices, int dst);
t_element	*optimize(t_info *info);
int			*parse_to_array(int argc, char *argv[], int total_size);
void		sort_five_or_less(t_info *info);
void		sort_main(t_info *info, int *array_of_nums);
void		sort_more_than_five(t_info *info);
int			push_integer(t_stack *stack, int value);
int			push_element_to_stack(t_stack *stack, t_element *new);
t_element	*pop_element_from_stack(t_stack *stack);
t_stack		*create_stack(void);
void		delete_stack(t_stack **stack);
t_element	*seek_bottom(t_stack *stack);

#endif
