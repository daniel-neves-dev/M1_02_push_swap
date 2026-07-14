/*
Caso 1: maior, menor, meio -> troca e rotaciona
Caso 2: ordem decrescente -> troca e rotação reversa
Caso 3: meio, menor, maior -> apenas troca
Caso 4: menor, maior, meio -> troca e rotaciona
Caso 5: meio, maior, menor -> rotação reversa
se não, Já está ordenado.
*/
#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_two(t_list **stack_a)
{
	int	a;
	int	b;

	a = *(int* )(*stack_a)->content;
	b = *(int* )(*stack_a)->next->content;
	if (a > b)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = *(int* )(*stack_a)->content;
	b = *(int* )(*stack_a)->next->content;
	c = *(int* )(*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (stack_size(*stack_a) > 3)
		move_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!(stack_a || *stack_a || (*stack_a)->next))
		return ;
	if (is_sorted(*stack_a))
		return ;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}
