//K-Sort, Chunk Sort
#include "push_swap.h"

static int	get_range(int size)
{
	if (size <= 20)
		return (4);
	if (size <= 100)
		return(15);
	return (35);
}

void	quick_push_to_b(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	i;
	int	range;

	i = 0;
	range = get_range(stack_size(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, bench);
			rb(stack_b, bench);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, bench);
			i++;
		}
		else
		{
			ra(stack_a, bench);
		}
	}
}

static int	get_max_positio(t_list *stack, int max_index)
{
	int	position;

	position = 0;
	while (stack && stack->index != max_index)
	{
		position++;
		stack = stack->next;
	}
	return(position);
}

//Volta de B para A buscando o maior numero.
void	push_back_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	position_max_index;
	int	size;

	while (*stack_b)
	{
		size = stack_size(*stack_b);
		position_max_index = get_max_positio(*stack_b, size - 1);
		if (position_max_index <= size / 2) // Traz o valor ao topo (atalho)
		{
			while ((*stack_b)->index != (size - 1))
				rb(stack_b, bench);
		}
		else
		{
			while ((*stack_b)->index != (size - 1))
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
	}
}

void	sort_medium(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	quick_push_to_b(stack_a, stack_b, bench);
	push_back_to_a(stack_a, stack_b, bench);
}
