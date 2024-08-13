#include "pushswap.h"

int	error_msg_bonus(t_stack **a, t_stack **b, char *instruct)
{
	t_stack_clear(a);
	t_stack_clear(b);
	if (instruct)
		free(instruct);
	write(1, "Error\n", 6);
	return (0);
}