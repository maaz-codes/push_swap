#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	doubly_list
{
    int					content;
    struct doubly_list	*prev;
    struct doubly_list	*next;
}	stack;

stack	*stack_new(int number);
stack	*last_block(stack *a);
void	stack_add(stack **a, stack *new_block);
int		stack_len(stack *a);
stack	*stack_init(int *numbers, int len);

//instruct utils
void	swap(stack **a);
void    push(stack **a, stack **b);
void    rotate(stack **top);

//instructions
void	sa(stack **a);
void	sb(stack **b);
void	ss(stack **a, stack **b);
void    pa(stack **a, stack **b);
void    pb(stack **b, stack **a);
void    ra(stack **a);
void    rb(stack **b);
void    rr(stack **a, stack **b);

//to remove
void	print_stack(stack *a);
void	del_block(stack *a);
void	stack_clear(stack **a);

#endif