#include "pushswap.h"

int find_max(stack *a)
{
    int max;

    max = a->content;

    while (a != NULL)
    {
        if (a->content > max)
            max = a->content;
        a = a->next;
    }
    return (max);
}

int find_min(stack *a)
{
    int min;

    min = a->content;

    while (a != NULL)
    {
        if (a->content < min)
            min = a->content;
        a = a->next;
    }
    return (min);
}

void push_elements_to_b(stack **b, stack **a) // only takes a stack with elements more than 3
{
    while (stack_len(*a) != 3)
        pb(b, a);
}

void tiny_sort(stack **a)
{
    stack *block;
    int max;

    block = (*a);
    max = find_max(block);
    
    if ((*a)->content == max)
        ra(a);
    if ((*a)->next->content == max)
        rra(a);
    if ((*a)->content > (*a)->next->content)
        sa(a);
}

int target_element(int element, stack *a)
{
	long target_element;
	stack *temp;

	target_element = (long)INT_MAX + 1;
	temp = a;

	while (a != NULL)
	{
		if (element < a->content && target_element > a->content)
			target_element = a->content;
		a = a->next;
	}
	if (target_element == (long)INT_MAX + 1)
		target_element = find_min(temp);
	return ((int)target_element);
}

// void final_sort(stack **a)
// {
//     int max;
//     int mid_line;
//     int index;
//     stack *block;

//     block = (*a);
//     max = find_max(block);
//     mid_line = stack_len(block) / 2;
//     if (stack_len(block) % 2 != 0)
//         mid_line++;
//     index = 1;
//     while (block->content != max)
//     {
//         index++;
//         block = block->next;
//     }
//     if (index < mid_line)
//         while (index-- > 0)
//             ra(a);
//     else
//         while ((stack_len(*a)) - index++ > 0)
//             rra(a);
// }

void final_sort(stack **a)
{
    int max;
    int mid_line;
    int index;
    stack *block;

    block = (*a);
    max = find_max(block);
    mid_line = stack_len(block) / 2;
    if (stack_len(block) % 2 != 0)
        mid_line++;
    index = 1;
    while (block->content != max)
    {
        index++;
        block = block->next;
    }
    if (index < mid_line)
        while (index-- > 0)
            rra(a);
    else
        while ((stack_len(*a)) - index++ > 0)
            ra(a);
}