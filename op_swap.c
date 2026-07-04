#include "push_swap.h"

void	sa(t_list **stack_a)
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

	ft_printf("sa\n");
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