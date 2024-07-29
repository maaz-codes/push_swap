#include "pushswap.h"

void swap(stack **a)
{
    stack *block1;
    stack *block2;
    
    if (*a == NULL || (*a)->next == NULL) {
        // List has less than two nodes, no swap possible
        return;
    }

    block1 = *a;
    block2 = (*a)->next;
    block1->prev = block2;
    block1->next = block2->next;
    block2->prev = block1->prev;
    block2->next = block1;
    (*a) = block2;
    return ;
}

void push(stack **a, stack **b)
{
    stack *temp_a;
    stack *temp_b;  

    temp_b = (*b);
    temp_a = (*a);
    // stack b
    *b = (*b)->next;
    (*b)->prev = NULL;

    // stack a
    (*a)->prev = temp_b;
    *a = temp_b;
    (*a)->next = temp_a;
}

void rotate(stack **top)
{
    stack *first;
    stack *last;

    if (*top == NULL || (*top)->next == NULL) 
        return ;

    first = (*top);
    last = (*top);

    while (last->next != NULL)
        last = last->next;

    // top points to block 2 
    (*top) = first->next;
    (*top)->prev = NULL;

    // putting block 1 at last
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void reverse_rotate(stack **top)
{
    stack *last;
    stack *second_last;

    if (*top == NULL || (*top)->next == NULL) 
        return ;
    last = *top;
    while (last->next != NULL)
        last = last->next;
    second_last = last->prev;
    second_last->next = NULL;
    last->prev = NULL;
    last->next = (*top);
    (*top)->prev = last;
    (*top) = last;
}
