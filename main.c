#include "pushswap.h"

int total_moves = 0;

void sorting(stack **a, stack **b)
{
	push_elements_to_b(b, a);  // step : 1
	tiny_sort(a);  // step : 2
	while (stack_len(*b) != 0) // step : 3
	{
		push_cheapest_element(a, b);
	}
	final_sort(a);
}

int	main(void)
{
    stack *a;
	stack *b;
	int arr[100] = {37, 85, 2, 61, 28, 49, 97, 23, 59, 9, 78, 90, 8, 42, 19, 68, 72, 53, 15, 26, 100, 6, 34, 75, 31, 50, 40, 95, 11, 64, 22, 81, 30, 14, 67, 86, 1, 48, 17, 63, 71, 25, 93, 36, 84, 5, 20, 57, 94, 32, 77, 3, 41, 98, 54, 12, 47, 92, 7, 66, 29, 60, 10, 76, 18, 55, 38, 87, 4, 27, 88, 45, 91, 13, 44, 52, 99, 33, 74, 21, 43, 56, 69, 16, 80, 35, 65, 58, 70, 46, 79, 24, 62, 39, 73, 82, 83, 89, 51, 96};

	// int arr[10] = {3, 6, 2, 1, 5};
	// int arr2[] = {-1};
		
	// a = stack_init(arr, 500);
	// int num[] = {6, 8, 7, 4, 3, 2, 1};
	a = stack_init(arr, 100);
	// b = stack_init(arr2, 1);
    b = malloc(sizeof(stack));
    printf("COntent = %d\n", b->content);


	// print_stack(b);

	sorting(&a, &b);
	print_stack(a);

	// print_stack(a);
	// printf("Moves = %d\n", total_moves);
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
	// stack_clear(&a);
	// stack_clear(&b);
}