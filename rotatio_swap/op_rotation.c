#include "push_swap.h"

void	ra(t_list **stack_a, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf(1, "ra\n");
	if (bench)
	{
		bench->ra++;
		bench->total_op++;
	}
}

void	rb(t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf(1, "rb\n");
	if (bench)
	{
		bench->rb++;
		bench->total_op++;
	}
}

void	rr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		first->next = NULL;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		first->next = NULL;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	ft_printf(1, "rr\n");
	if (bench)
	{
		bench->ra++;
		bench->total_op++;
	}
}
