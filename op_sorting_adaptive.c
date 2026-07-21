#include "push_swap.h"

static double	calculate_disorder(t_list *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*i;
	t_list	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				mistakes += 1;
			total_pairs++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)(mistakes / total_pairs)*100);
}

void	sort_adaptive(t_list **stack_a, t_list **stack_b)
{
	double	disorder;

	disorder = calculate_disorder(*stack_a);

	if (disorder <= 15.0 || *(int *)(*stack_a) <= 5)
		sort_simple(stack_a, stack_b);
	else if (disorder <= 100.0)
		sort_medium(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
}
