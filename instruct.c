#include "pushswap.h"

extern int total_moves;

void sa(stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(stack **a, stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void pa(stack **a, stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
    total_moves++;

}

void pb(stack **b, stack **a)
{
    push(b, a);
    write(1, "pb\n", 3);
    total_moves++;

}

void ra(stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
    total_moves++;

}

void rb(stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
    total_moves++;

}

void rr(stack **a, stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
    total_moves++;

}

void rra(stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
    total_moves++;
}
void rrb(stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}
void rrr(stack **a, stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}