#include "push_swap.h"

static char	*get_flag_name(t_flags *flags, double disorder)
{
	t_flagtype	strat;

	strat = flags->flagtype;

	if (strat == STRAT_SIMPLE)
		return ("Simple / O(n^2)");
	if (strat == STRAT_MEDIUM)
		return ("Medium / O(n√n)");
	if (strat == STRAT_COMPLEX)
		return ("Complex / O(n log n)");
	if (strat == STRAT_ADAPTIVE)
	{
		if (disorder < 20)
			return ("Adaptive / O(n^2)");
		else if (disorder < 50)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(n log n)");
	}
	return ("unknow");
}

static void	print_disorder_bench(int fd, double disorder)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(disorder);
	dec_part = (int)((disorder - int_part)*100);

	if(dec_part < 10)
		ft_printf(fd, "[bench] disorder: %d.0%d%%\n", int_part, dec_part);
	else
		ft_printf(fd, "[bench] disorder: %d.%d%%\n", int_part, dec_part);
}

void	print_bench(double disorder, t_flags *flags, t_bench *bench)
{
	char	*strat;

	strat = get_flag_name(flags, disorder);
	print_disorder_bench(2, disorder);
	ft_printf(2, "[bench] strategy: %s\n", strat);
	ft_printf(2, "[bench] total_ops: %d\n", bench->total_op);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d\n",
		bench->ra, bench->rb, bench->rr);
	ft_printf(2, "[bench] rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rrr);
}
