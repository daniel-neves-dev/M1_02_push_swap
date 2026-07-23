#include "push_swap.h"
///DELETAR NO FIM DO PROJETO
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
//////

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
	print_stack("A", stack_a); ///DELETAR NO FIM DO PROJETO
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
