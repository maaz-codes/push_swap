#include "../pushswap.h"

void sa(stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void pa(stack **a, stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void ra(stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rra(stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}
