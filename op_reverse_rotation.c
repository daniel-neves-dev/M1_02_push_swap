#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;
	t_list	*penultimete;

	first = *stack_a;
	first->prev = NULL;
	last = ft_lstlast(*stack_a);
	while (first->next != NULL)
	{
		penultimete = first;
		first = first->next;
	}
	penultimete->next = NULL;
	first->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}
