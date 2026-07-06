#include "push_swap.h"

void    ra(t_list **stack_a)
{
	t_list  *first;
	t_list  *last;

	if (!stack_a || !*stack_a)
		return;

	first = *stack_a;
	*stack_a = first->next;
	first->prev = NULL;

	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;

	ft_printf("ra\n");
}