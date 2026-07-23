#include "push_swap.h"

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
	int			i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	n = ft_atoi(arg);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

int	fill_stack(t_list **stack_a, int argc, char **argv, int arg_start)
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
	double	disorder;
	t_bench	bench;

	ft_memset(&bench, 0, sizeof(t_bench));
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (is_sorted(*stack_a))
		return ;
	index_stack(*stack_a);
	disorder = calculate_disorder(*stack_a);
	execution_flags(stack_a, stack_b, flags, &bench);
	if (flags->bench_mode)
		print_bench(disorder, flags, &bench);
}
