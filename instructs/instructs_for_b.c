#include "../pushswap.h"

void sb(stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}


void pb(stack **b, stack **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}


void rb(stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rrb(stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}
