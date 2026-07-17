#include "push_swap.h"

static int	get_flag(char *arg)
{
	if (ft_strncmp(arg, "--simple", ft_strlen(arg)) == 0)
		return(STRAT_SIMPLE);
	return (0);
}

int	parse_flags(int argc, char **argv, t_params *params)
{
	int	i;
	int	strat;

	params->flagtype = STRAT_NONE;
	params->bench_mode = 0;
	params->disorder = 0.0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
				params->bench_mode = 1;
			else
			{
				strat = get_flag(argv[i]);
				if (strat != STRAT_NONE)
					params->flagtype = strat;
			}
			i++;
		}
		else
		{
			break ;
		}
	}
	return (i);
}

void	execution_flags(t_list **stack_a, t_list **stack_b, t_params *params)
{
	int size;

	size = stack_size(*stack_a);
	if (params->flagtype == STRAT_SIMPLE && size <= 5)
	{
		sort_simple(stack_a, stack_b);
		return ;
	}
	sort_big(stack_a, stack_b);
}
/* data */
