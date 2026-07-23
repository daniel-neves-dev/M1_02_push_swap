#include "push_swap.h"

void	rra(t_list **stack_a, t_bench *bench)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
	if (bench)
	{
		bench->rra++;
		bench->total_op++;
	}
}

void	rrb(t_list **stack_b, t_bench *bench)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
	if (bench)
	{
		bench->rrb++;
		bench->total_op++;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*prev;
	t_list	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		prev = NULL;
		last = *stack_a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		prev = NULL;
		last = *stack_b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	ft_printf("rrr\n");
	if (bench)
	{
		bench->rrr++;
		bench->total_op++;
	}
}
