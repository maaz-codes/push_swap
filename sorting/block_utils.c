#include "../pushswap.h"

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
