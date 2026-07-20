#include "push_swap.h"

// Encontra o número de bits necessários para representar o maior índice (size - 1)
static int	get_max_bit(t_list *stack)
{
	int	index_max;
	int	bit_max;

	index_max = stack_size(stack) - 1;
	bit_max = 0;
	while ((index_max >> bit_max) > 0) // aloca o bit ate atingir zero dividindo o numero por 2 e comparando como bit.
		bit_max++;
	return (bit_max);
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*stack_a);
	max_bits = get_max_bit(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i & 1) == 0) // se o bit em i for zero empurra para 'b'
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b) // devolve para 'a' para analisar o proximo bit.
			pa(stack_a, stack_b);
		i++;
	}
}
