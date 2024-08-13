#include "../pushswap.h"

void	ss_checker(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	rr_checker(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr_checker(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
