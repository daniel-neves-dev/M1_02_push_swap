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

static int	fill_stack(t_list **stack_a, int argc, char **argv, int arg_start)
{
	t_list		*new_node;
	long long	*numbers;
	int			i;

	i = arg_start;
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

void	push_swap(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (is_sorted(*stack_a))
		return ;
	index_stack(*stack_a);
	execution_flags(stack_a, stack_b, flags);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_flags		flags;
	int			arg_start;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	arg_start = parse_flags(argc, argv, &flags);
	if (arg_start >=  argc)
		return (0);
	if (fill_stack(&stack_a, argc, argv, arg_start) == 0)
	{
		print_error();
		free_stack(&stack_a);
		return (1);
	}
	push_swap(&stack_a, &stack_b, &flags);
	print_stack("A", stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
