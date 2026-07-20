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
	int			bench_mode; // ativa e desativa o --bench(1 e 0)
	double		disorder;
}	t_flags;


void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	free_stack(t_list **stack);
void	print_error(void);
void	ft_putstr(char *str);
int		stack_size(t_list *stack);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		get_index(t_list *stack, int value);
int		is_sorted(t_list *stack);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);

void	sort_big(t_list **stack_a, t_list **stack_b);
void	move_min_to_b(t_list **stack_a, t_list **stack_b);
void	index_stack(t_list *stack_a);

int		parse_flags(int argc, char **argv, t_flags *flags);
void	execution_flags(t_list **stack_a, t_list **stack_b, t_flags *flags);

void	sort_simple(t_list **stack_a, t_list **stack_b);
void	sort_medium(t_list **stack_a, t_list **stack_b);
void	sort_complex(t_list **stack_a, t_list **stack_b);

void	push_swap(t_list **stack_a, t_list **stack_b, t_flags *flags);

#endif
