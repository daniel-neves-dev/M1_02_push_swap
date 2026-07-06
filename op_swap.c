#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
	t_list  *first;

	if (!stack_b || !*stack_b)
		return;
	first = *stack_b;
	*stack_b = first->next;
	first->next = *stack_a;
	*stack_a = first;
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	if (!stack_a || !*stack_a)
		return ;

	first = *stack_a;
	*stack_a = first->next;
	first->next = *stack_b;
	*stack_b = first;
	ft_printf("pb\n");
}

void    sa(t_list **stack_a)
{
	t_list  *first;
	t_list  *second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_printf("sa\n");
}

void    sb(t_list **stack_b)
{
	t_list  *first;
	t_list  *second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_printf("sb\n");
}

void    ss(t_list **stack_a, t_list **stack_b)
{
	t_list *first;
	t_list *second;

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
	ft_printf("ss\n");
}