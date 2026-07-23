# include "push_swap.h"
 //Retorna o menor número da pilha que ainda não foi indexado (-1 significa já indexado)
static t_list	*find_next_min(t_list *stack)
{
	t_list	*min_node;
	t_list	*current_node;

	min_node = NULL;
	current_node = stack;

	while(current_node)
	{
		if(current_node->index == -1)
		{
			if(!min_node
				|| *(int *)current_node->content < *(int *)min_node->content)
				min_node = current_node;
		}
		current_node = current_node->next;
	}
	return (min_node);
}
// Atribui um índice de 0 a (size - 1) para cada nó da stack_a
void	index_stack(t_list *stack_a)
{
	t_list	*min_node;
	t_list	*current_node;
	int		index;
	int		size;

	current_node = stack_a;
	while (current_node)
	{
		current_node->index = -1; // inicializa todos os indices com -1
		current_node = current_node->next;
	}

	size = stack_size(stack_a);
	index = 0;
	while (index < size)
	{
		min_node = find_next_min(stack_a);
		if(min_node)
			min_node->index = index;
		index++;
	}
}
