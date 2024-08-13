
#include "../pushswap.h"

void	sa_checker(t_stack **a)
{
	swap(a);
}

void	pa_checker(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	ra_checker(t_stack **a)
{
	rotate(a);
}

void	rra_checker(t_stack **a)
{
	reverse_rotate(a);
}