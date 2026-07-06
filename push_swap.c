#include "push_swap.h"

/*void	print_list(t_list *stack_a, t_list *stack_b)
{
	ft_printf("  a   b\n");
	ft_printf("----------\n");
	while (stack_a || stack_b)
	{
		// Se houver elemento em A, printa o número, senão printa um espaço vazio
		if (stack_a)
		{
			ft_printf("%d  ", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("     ");

		// Se houver elemento em B, printa o número, senão deixa vazio
		if (stack_b)
		{
			ft_printf("%d\n", *(int *)stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("  \n");
	}
	ft_printf("----------\n\n");
}

void	free_numb(void *content)
{
	free(content);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_node;
	int		*numbers;
	int		i;

	if (argc < 2)
		return (1);

	stack_a = NULL;
	i = 1;

	while (i < argc)
	{
		numbers = malloc(sizeof(int));
		if (!numbers)
		{
			ft_lstclear(&stack_a, free_numb);
			return (1);
		}

		*numbers = ft_atoi(argv[i]);
		new_node = ft_lstnew(numbers);
		if (!new_node)
		{
			ft_lstclear(&stack_a, free_numb);
			return (1);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	ft_printf("Init a and b:\n");
	print_list(stack_a, stack_b);

	ft_printf("(swap a): Swap the first two elements at the top of stack 'a'. Do nothing if there is only one or no elements.\n");
	sa(&stack_a);
	print_list(stack_a, stack_b);

	ft_printf("(push b): Take the first element at the top of 'a' and put it at the top of 'b'. Do nothing if a is empty.\n");
	int t = 0;
	while (t < 3) {
		pb(&stack_a, &stack_b);
		print_list(stack_a, stack_b);
		t++;
	}
	ft_lstclear(&stack_a, free_numb);
	ft_lstclear(&stack_b, free_numb);
	return (0);
}
*/
static t_list *new_node(int value)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = (void *)(long)value;
	node->next = NULL;
	return (node);
}

static void	add_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void	print_stack(char *name, t_list *stack)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", (int)(long)stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	add_back(&a, new_node(1));
	add_back(&a, new_node(2));
	add_back(&a, new_node(3));

	add_back(&b, new_node(4));
	add_back(&b, new_node(5));
	add_back(&b, new_node(6));

	print_stack("A", a);
	print_stack("B", b);

	sa(&a);
	print_stack("A", a);

	sb(&b);
	print_stack("B", b);

	pa(&a, &b);
	print_stack("A", a);
	print_stack("B", b);

	pb(&a, &b);
	print_stack("A", a);
	print_stack("B", b);

	ss(&a, &b);
	print_stack("A", a);
	print_stack("B", b);

	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);

	return (0);
}