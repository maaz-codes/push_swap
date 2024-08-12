#include "../pushswap.h"

void ss(stack **a, stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void rr(stack **a, stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void rrr(stack **a, stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
