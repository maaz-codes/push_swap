#include "pushswap.h"

stack *find_max_block(stack *a)
{
    stack *max;

    max = a;

    while (a != NULL)
    {
        if (a->content > max->content)
            max = a;
        a = a->next;
    }
    return (max);
}

stack *find_min_block(stack *a)
{
    stack *min;

    min = a;

    while (a != NULL)
    {
        if (a->content < min->content)
            min = a;
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
    max = find_max_block(block)->content;
    
    if ((*a)->content == max)
        ra(a);
    if ((*a)->next->content == max)
        rra(a);
    if ((*a)->content > (*a)->next->content)
        sa(a);
}

static stack *target_block_for_a(stack *element, stack *a)
{
	long target_element;
	stack *temp;
	stack *target;

	target_element = (long)INT_MIN - 1;
	target = a;
	temp = a;

	while (a != NULL)
	{
		if (element->content > a->content && target_element < a->content)
		{
			target_element = a->content;
			target = a;
		}
		a = a->next;
	}
	if (target_element == (long)INT_MIN - 1)
		target = find_max_block(temp);
	return (target);
}

static stack *target_block_for_b(stack *element, stack *a)
{
	long target_element;
	stack *temp;
	stack *target;

	target_element = (long)INT_MAX + 1;
	target = a;
	temp = a;

	while (a != NULL)
	{
		if (element->content < a->content && target_element > a->content)
		{
			target_element = a->content;
			target = a;
		}
		a = a->next;
	}
	if (target_element == (long)INT_MAX + 1)
		target = find_min_block(temp);
	return (target);
}

stack *target_block(stack *element, stack *s, char stacks)
{
	stack *target;

	if (stacks == 'a')
		target = target_block_for_a(element, s);
	else if (stacks == 'b')
		target = target_block_for_b(element, s);
	else
		target = NULL;
	return (target);
}

void final_sort(stack **a)
{
    int max;
    int mid_line;
    int index;
    stack *block;

    block = (*a);
    max = find_max_block(block)->content;
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
            ra(a);
    else
        while ((stack_len(*a)) - index++ > 0)
            rra(a);
}

int index_to_top(stack *element, stack *s)
{
	int index;
	int mid_line;
	int len;
	int index_to_top;

	index = 0;
	len = stack_len(s);
	if (len % 2 == 0)
		mid_line  = len / 2;
	else
		mid_line = (len / 2) + 1;
	while (s != NULL)
	{
		if (s->content == element->content)
			break ;
		index++;
		s = s->next;
	}
	if (index >= mid_line)
		index_to_top = (len - index) * -1;
	else
		index_to_top = index;
	s->index_to_top = index_to_top;
	return (index_to_top);
}

int push_cost(stack *a, stack *b, stack *element, stack *target)
{
    int index_to_top_a = index_to_top(element, b);  
    int index_to_top_b = index_to_top(target, a); 
    int push_price;

    if (index_to_top_a * index_to_top_b >= 0) 
        if (ft_abs(index_to_top_a) > ft_abs(index_to_top_b))
            push_price = ft_abs(index_to_top_a);
        else
            push_price = ft_abs(index_to_top_b); 
	else 
        push_price = ft_abs(index_to_top_a) + ft_abs(index_to_top_b);

    return (push_price + 1);
}

stack *cheapest_block(stack *a, stack *b)
{
	int least_price;
	int push_price;
	stack *cheapest_block;
	stack *temp_b;

	least_price = push_cost(a, b, b, target_block(b, a, 'b'));
	cheapest_block = b; // 1st node
	temp_b = b;
	while (b != NULL)
	{
		push_price = push_cost(a, temp_b, b, target_block(b, a, 'b'));
		if (push_price < least_price)
		{
			cheapest_block = b;
			least_price = push_price;
		}
		b = b->next;
	}
	return (cheapest_block);
}
