#include  "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, del);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}