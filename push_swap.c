#include "push_swap.h"

static void	print_stack(char *name, t_list *stack)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", *(int *)stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

static int	duplicate_number(t_list *stack, long long n)
{
	while (stack)
	{
		if (*(int *)stack->content == n)
			return (0);
		stack = (stack)->next;
	}
	return (1);
}

static int	valid_arg(char *arg)
{
	long long	n;

	if (*arg == '-' || *arg == '+')
		arg++;
	if (*arg == '\0')
		return (0);
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (0);
		arg++;
	}
	n = ft_atoi(arg);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

static int	fill_stack(t_list **stack_a, int argc, char **argv)
{
	t_list		*new_node;
	long long	*numbers;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (valid_arg(argv[i]) == 0 ||
			duplicate_number(*stack_a, ft_atoi(argv[i])) == 0)
			return (0);
		numbers = malloc(sizeof(long long));
		if (!numbers)
			return (0);
		*numbers = ft_atoi(argv[i]);
		new_node = ft_lstnew(numbers);
		if (!new_node)
		{
			free(numbers);
			return (0);
		}
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (fill_stack(&stack_a, argc, argv) == 0)
	{
		print_error();
		free_stack(&stack_a);
		return (1);
	}

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

/*
static	t_list *new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = (void *)(long)value;
	node->next = NULL;
	return (node);
}

static void	add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

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
*/

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	add_back(&a, new_node(2));
	add_back(&a, new_node(1));
	add_back(&a, new_node(3));

	add_back(&a, new_node(6));
	add_back(&a, new_node(5));
	add_back(&a, new_node(8));

	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	sa(&a);
	print_stack("A", a);
	ft_printf("\n");

	rra(&a);
	print_stack("A", a);
	ft_printf("\n");

	int	j = 0;
	while (j < 3)
	{
		pb(&a, &b);
		print_stack("A", a);
		print_stack("B", b);
		ft_printf("\n");
		j++;
	}

	ra(&a);
	print_stack("A", a);
	ft_printf("\n");


	sb(&b);
	print_stack("B", b);
	ft_printf("\n");

	pa(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	ss(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	ft_printf("Testing rb:\n");
	rb(&b);
	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	ft_printf("Testing rr:\n");
	rr(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	ft_printf("Testing rrb:\n");
	rrb(&b);
	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	ft_printf("Testing rrr:\n");
	rrr(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	ft_printf("\n");

	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);

	return (0);
}
*/
