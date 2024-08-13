#include "../pushswap.h"

void	sb_checker(t_stack **b)
{
	swap(b);
}

void	pb_checker(t_stack **b, t_stack **a)
{
	push(b, a);
}

void	rb_checker(t_stack **b)
{
	rotate(b);
}

void	rrb_checker(t_stack **b)
{
	reverse_rotate(b);
}
