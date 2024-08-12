#include "../pushswap.h"

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