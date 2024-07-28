#include "pushswap.h"

void sa(stack **a)
{
    swap(a);
}

void sb(stack **b)
{
    swap(b);
}

void ss(stack **a, stack **b)
{
    swap(a);
    swap(b);
}

void pa(stack **a, stack **b)
{
    push(a, b);
}

void pb(stack **b, stack **a)
{
    push(b, a);
}

// void ra(stack **a)
// {
//     printf("Controller \n");
//     // rotate(a);
// }

void ra(stack **a)
{
    rotate(a);
    printf("Controller %d\n", (*a)->content);
}

void rb(stack **b)
{
    rotate(b);
}

void rr(stack **a, stack **b)
{
    rotate(a);
    rotate(b);
}

void rra(stack **a)
{
    reverse_rotate(a);
}
void rrb(stack **b)
{
    reverse_rotate(b);
}
void rrr(stack **a, stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}