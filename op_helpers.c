#include "push_swap.h"

int	stack_size(t_list *stack)
{
	return (ft_lstsize(stack));
}

int	find_min(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_index(t_list *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

void	move_min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	index;
	int	size;

	min = find_min(*stack_a);
	index = get_index(*stack_a, min);
	size = stack_size(*stack_a);
	if (index <= size / 2)
	{
		while ((*stack_a)->value != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
