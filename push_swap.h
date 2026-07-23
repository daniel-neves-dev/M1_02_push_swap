#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef enum e_flagtype
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
}	t_flagtype;

typedef struct s_flags
{
	t_flagtype	flagtype;
	int			bench_mode;
}	t_flags;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_op;
}t_bench;


void	sa(t_list **stack_a, t_bench *bench);
void	sb(t_list **stack_b, t_bench *bench);
void	ss(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	pa(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	pb(t_list **stack_a, t_list **stack_b, t_bench *bench);

void	ra(t_list **stack_a, t_bench *bench);
void	rb(t_list **stack_b, t_bench *bench);
void	rr(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	rra(t_list **stack_a, t_bench *bench);
void	rrb(t_list **stack_b, t_bench *bench);
void	rrr(t_list **stack_a, t_list **stack_b, t_bench *bench);

int		fill_stack(t_list **stack_a, int argc, char **argv, int arg_start);
void	free_stack(t_list **stack);
void	print_error(void);
void	ft_putstr(char *str);
int		stack_size(t_list *stack);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		get_index(t_list *stack, int value);
int		is_sorted(t_list *stack);
void	sort_two(t_list **stack_a, t_bench *bench);
void	sort_three(t_list **stack_a, t_bench *bench);
double	calculate_disorder(t_list *stack);

void	move_min_to_b(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	index_stack(t_list *stack_a);

int		parse_flags(int argc, char **argv, t_flags *flags);
void	execution_flags(t_list **stack_a, t_list **stack_b, t_flags *flags, t_bench *bench);

void	sort_simple(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	sort_medium(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	sort_complex(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	print_bench(double disorder, t_flags *flags, t_bench *bench);

void	push_swap(t_list **stack_a, t_list **stack_b, t_flags *flags);

#endif
