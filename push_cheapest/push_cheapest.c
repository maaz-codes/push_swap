#include "../pushswap.h"

void rotate_ab(stack **a, stack **b, stack *cheapest, stack *target)
{
	rr(a, b);
	cheapest->index_to_top--;
	target->index_to_top--;
}

void elements_to_top(stack *cheapest, stack *target, stack **a, stack **b)
{
        if (cheapest->index_to_top > 0 && target->index_to_top > 0) 
			rotate_ab(a, b, cheapest, target);
        else if (cheapest->index_to_top < 0 && target->index_to_top < 0) 
            reverse_rotate_ab(a, b, cheapest, target);
		else 
		{
            if (target->index_to_top > 0) 
                rotate_a(a, target);
			else if (target->index_to_top < 0) 
                reverse_rotate_a(a, target);
            if (cheapest->index_to_top > 0) 
                rotate_b(b, cheapest);
			else if (cheapest->index_to_top < 0) 
                reverse_rotate_b(b, cheapest);
		}
}

void push_cheapest_element(stack **a, stack **b)
{
	stack *cheapest;
	stack *target;

	cheapest = cheapest_block((*a), (*b)); 
	target = target_block(cheapest, (*a), 'b');
	while (index_to_top(cheapest, (*b)) != 0 || index_to_top(target, (*a)) != 0)
	{
		elements_to_top(cheapest, target, a, b);
	}
	pa(a, b);
}