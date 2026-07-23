/*
Caso 1: maior, menor, meio -> troca e rotaciona
Caso 2: ordem decrescente -> troca e rotação reversa
Caso 3: meio, menor, maior -> apenas troca
Caso 4: menor, maior, meio -> troca e rotaciona
Caso 5: meio, maior, menor -> rotação reversa
se não, Já está ordenado.
*/
//Selection Sort
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

void	sort_two(t_list **stack_a, t_bench *bench)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a, bench);
}

void	sort_three(t_list **stack_a, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	c = *(int *)(*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack_a, bench);
	else if (a > b && b > c)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, bench);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, bench);
}

static void	sort_selection_n2(t_list **stack_a, t_list **stack_b, t_bench *bench) // agortimo n2
{
	while (stack_size(*stack_a) > 3)
		move_min_to_b(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}

void	sort_simple(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_two(stack_a, bench);
	else if (size == 3)
		sort_three(stack_a, bench);
	else
		sort_selection_n2(stack_a, stack_b, bench); // atende ate 500 numeros em n2
}
