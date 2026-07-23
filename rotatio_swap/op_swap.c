#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*first;

	if (!stack_b || !*stack_b)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = *stack_a;
	*stack_a = first;
	ft_printf(1, "pa\n");
	if (bench)
	{
		bench->pa++;
		bench->total_op++;
	}
}

void	pb(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*first;

	if (!stack_a || !*stack_a)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = *stack_b;
	*stack_b = first;
	ft_printf(1, "pb\n");
	if (bench)
	{
		bench->pb++;
		bench->total_op++;
	}
}

void	sa(t_list **stack_a, t_bench *bench)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_printf(1, "sa\n");
	if (bench)
	{
		bench->sa++;
		bench->total_op++;
	}
}

void	sb(t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_printf(1, "sb\n");
	if (bench)
	{
		bench->sb++;
		bench->total_op++;
	}
}

void	ss(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*second;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
	}
	ft_printf(1, "ss\n");
	if (bench)
	{
		bench->ss++;
		bench->total_op++;
	}
}
