#include "push_swap.h"

void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	double	disorder;
	disorder = calculate_disorder(*stack_a);

	if (disorder < 20.0 || stack_size(*stack_a) < 6)
		sort_simple(stack_a, stack_b, bench);
	else if (disorder < 50.0)
		sort_medium(stack_a, stack_b, bench);
	else
		sort_complex(stack_a, stack_b, bench);
}
