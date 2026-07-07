#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	i;
	int	size;

	size = stack_size(*stack_a);
	i = -1;
	while (++i < size - 3)
	{
		if ((*stack_a)->value <= i + chunk)
			pb(stack_a, stack_b);
		else if ((*stack_a)->value <= i + chunk * 2)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if (*stack_a && (*stack_a)->next
			&& (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}

void	final_rotate(t_list **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a))
		ra(stack_a);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	chunk;

	chunk = stack_size(*stack_a) / 5;
	if (chunk < 10)
		chunk = 10;
	push_to_b(stack_a, stack_b, chunk);
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	final_rotate(stack_a);
}