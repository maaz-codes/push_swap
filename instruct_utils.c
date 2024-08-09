#include "pushswap.h"

void swap(stack **a) 
{
    stack *first; 
    stack *second;

    if (*a == NULL || (*a)->next == NULL)
        return;

    first = *a;
    second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
}

void push(stack **a, stack **b) 
{
    stack *temp;

    if (*b == NULL) 
        return ;
    
    temp = (*b);
    (*b) = (*b)->next;

    if ((*a) == NULL)
    {
        temp->next = NULL;
        (*a) = temp;
    }
    else
    {
        temp->next = *a;
        *a = temp;
    }
}

void rotate(stack **a) 
{
    stack *temp;
    stack *current;

    if (*a == NULL || (*a)->next == NULL)
        return;
    temp = *a;
    *a = (*a)->next;
    current = *a;
    while (current->next != NULL) 
        current = current->next;
    current->next = temp;
    temp->next = NULL;
}

void reverse_rotate(stack **a) 
{
    stack *prev;
    stack *current;

    if (*a == NULL || (*a)->next == NULL) 
        return;
    prev = NULL;
    current = *a;
    while (current->next != NULL) 
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = *a;
    *a = current;
}
