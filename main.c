#include "pushswap.h"

// void push_cheapest_element(stack **a, stack **b, int cheapest_element, int target)
// {
// 	int operation_on_element;
// 	int operation_on_target;

// 	operation_on_element = index_to_top(cheapest_element, (*b)); // 1
// 	operation_on_target = index_to_top(target, (*a)); // 2

// 	if (operation_on_element * operation_on_target >= 0) // same signs
// 	{
// 		if (operation_on_element < 0) // both -ve
// 			rotate_push(a, b, -1, -1);
// 		else // both +ve
// 		{
// 			rotate_push(a, b, 1, 1);
// 		}
// 	}


// }

void rotate_both(int index_a, int index_b, stack **a, stack **b, int is_same)
{
	while (index_a != 0 || index_b != 0)
	{
		if (index_a * index_b >= 0)
		{
			if (index_a < 0) // both -ve
			{
				
			}
			else // both +ve
			{

			}
		}
		else 
		{

		}
	}
}

void empty_stack_b(stack **a, stack **b)
{
	stack *cheapest;
	stack *target;
	int index_a;
	int index_b;

	cheapest = cheapest_block((*a), (*b)); // 1 (+1)
	target = target_block(cheapest->content, (*a), 'b'); // 4 (-2)
	index_a = index_to_top(cheapest->content, (*b));
	index_b = index_to_top(target->content, (*a));

	while (index_a != 0 && index_b != 0)
	{
		if (index_a * index_b >= 0 )
			rotate_both(index_a, index_b, a, b, 1); // 1 for both are same signs
		else
			rotate_both(index_a, index_b, a, b, -1); // 0 both are different signs
	}
	pa(a, b);
}

void sorting(stack **a, stack **b)
{
	push_elements_to_b(b, a);  // step : 1
	tiny_sort(a);  // step : 2

	while (stack_len(*b) != 0)
	{
		empty_stack_b(a, b);
	}

}

int	main(void)
{
    stack *a;
	stack *b;
	int numbers[] = {8, 2, 4, 6};
	int nums[] = {3, 1, 5, 7};
	int index;
	int push_price;
		
	a = stack_init(numbers, 4);
	b = stack_init(nums, 4);
	print_stack(a);
	print_stack(b);

	// push_elements_to_b(&b, &a);
	// tiny_sort(&a);
	// final_sort(&b);
	// printf("Target = %d \n", target_element(7, a));

	// index = index_to_top(6, a);
	// printf("Index to top = %d\n", index);

	// int element = 5;
	// push_price = push_cost(a, b, element, target_element(element, a));
	// printf("Push_price = %d\n", push_price);

	stack *cheap_element = cheapest_block(a, b);
	printf("Cheapest Element = %d \n", cheap_element->content);
	// int is_sorted = 0;
	// if (!is_sorted)
	// {
	// 	if (stack_len(a) == 2)
	// 		sa(&a);
	// 	else if (stack_len(a) == 3)
	// 		tiny_sort(&a);
	// 	else
	// 		sorting(&a, &b);		
	// }

	// emptying_stack_b(&a, &b, cheapest_element(a, b));

	print_stack(a);
	print_stack(b);   


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
	// stack_clear(&a);
	// stack_clear(&b);
}