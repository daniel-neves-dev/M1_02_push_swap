#include "push_swap.h"

void	quick_push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min;

	while (stack_size(*stack_a) > 3)
	{
		min = find_min(*stack_a);
		if (get_index(*stack_a, min) <= stack_size(*stack_a) / 2)
		{
			while (*(int *)(*stack_a)->content != min)
				ra(stack_a);
		}
		else
		{
			while (*(int *)(*stack_a)->content != min)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	index;
	int	size;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		index = get_index(*stack_b, max);
		size = stack_size(*stack_b);
		if (index <= size / 2)
		{
			while (*(int *)(*stack_b)->content != max)
				rb(stack_b);
		}
		else
		{
			while (*(int *)(*stack_b)->content != max)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	quick_push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
}
