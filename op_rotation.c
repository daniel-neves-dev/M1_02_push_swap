#include "push_swap.h"

void    ra(t_list **stack_a)
{
	t_list  *first;
	t_list  *last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	t_list  *first;
	t_list  *last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list  *first;
	t_list  *last;

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
	ft_printf("rr\n");
}

void	rrb(t_list **stack_b)
{
	t_list  *prev;
	t_list  *last;

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
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list  *prev;
	t_list  *last;

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
}