
#include <stdio.h> ///REMOVER
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

void	print_bench(double disorder, t_flags *flags, t_bench *bench)
{
	char	*strat;

	strat = get_flag_name(flags, disorder);
	fprintf(stderr, "[bench] disorder: %2.f%%\n", disorder);
	fprintf(stderr, "[bench] strategy: %s\n", strat);
	fprintf(stderr, "[bench] total_ops: %d\n", bench->total_op);
	fprintf(stderr, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	fprintf(stderr, "[bench] ra: %d  rb: %d  rr: %d\n",
		bench->ra, bench->rb, bench->rr);
	fprintf(stderr, "[bench] rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rrr);
}
