#include "pushswap.h"

int *mid_line_inst(stack *block, int element)
{
	int mid_line;
	int index;
	stack *temp;
	int *count;

	count[0] = 0;
	count[1] = 0;
	mid_line = stack_len(block) / 2;
    if (stack_len(block) % 2 != 0)
        mid_line++;
    index = 1;
	temp = block;
    while (block->content != element)
    {
        index++;
        block = block->next;
    }
    if (index < mid_line)
        while (index-- > 0)
            count[1]++;
    else
        while ((stack_len(block)) - index++ > 0)
            count[0]++;
	return (count);
}

int push_cost(int element, stack *a, stack *b)
{
	int tar;
	int cost;
	int index_a;
	int index_b;

	cost = 0;
	tar = target_element(element, a);
	index_a = 1;
	index_b = 1;

	while (b->content != element)
    {
        index_a++;
        b = b->next;
    }
    if (index_a < (stack_len(b) / 2))
        while (index_a-- > 0)
            cost++;
    else
        while ((stack_len(b)) - index_a++ > 0)
            cost++;
	return (cost);
}

int	main(void)
{
    stack *a;
	stack *b;
	int numbers[] = {4, 1, 3, 6};
	int nums[] = {2, 8, 10, 5, 7, 9};
		
	a = stack_init(numbers, 4);
	b = stack_init(nums, 5);
	print_stack(a);
	print_stack(b);

	// push_elements_to_b(&b, &a);
	// tiny_sort(&a);
	final_sort(&b);
	// printf("Target = %d \n", target_element(7, a));
	// int element = 7;
	// printf("PUSH COST = %d \n", push_cost(element, a, b));
	int *count = mid_line_inst(a, 3);
	printf("MIDLINE : ra = %d | rra = %d \n", count[0], count[1]);

	print_stack(b);
	// print_stack(b);   





///////////  INSTRUCTIONS  ////////////

	// printf("After swap a : \n");
	// sa(&a);
	// sb(&b);
	// ss(&a, &b);

	// printf("After push a : \n");
	// pa(&a, &b);
	// pb(&b, &a);

	// printf("After rotate a : \n");
	// ra(&a);
	// rb(&b);
	// rr(&a, &b);

	// printf("After reverse rotate a : \n");
	// rra(&a);
	// rrb(&b);
	// rrr(&a, &b);

	// print_stack(a);
	// print_stack(b);
	stack_clear(&a);
	stack_clear(&b);
}