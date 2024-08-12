#include "../pushswap.h"

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
