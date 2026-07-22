#include "push_swap.h"

void	init_flags(t_flags *flags)
{
	flags->flagtype = STRAT_ADAPTIVE;
	flags->bench_mode = 0;
}
int	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	init_flags(flags); // se nao tiver '-' vai direto para o return i
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			flags->flagtype = STRAT_SIMPLE;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			flags->flagtype = STRAT_MEDIUM;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			flags->flagtype = STRAT_COMPLEX;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			flags->flagtype = STRAT_ADAPTIVE;
		else
			return (0);
		i++;
	}
	return (i);
}

void	execution_flags(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	t_flagtype	strat;

	strat = flags->flagtype;

	if (strat == STRAT_SIMPLE)
		sort_simple(stack_a, stack_b);
	else if (strat == STRAT_MEDIUM)
		sort_medium(stack_a, stack_b);
	else if (strat == STRAT_COMPLEX)
		sort_complex(stack_a, stack_b);
	else if (strat == STRAT_ADAPTIVE)
		sort_adaptive(stack_a, stack_b);
	else
		return ;
}
