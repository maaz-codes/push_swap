#include "pushswap.h"

int	main(void)
{
    stack *a;
	stack *b;
	int numbers[] = {1, 2, 3, 4, 5};
	int num[] = {10, 20 ,30};
	a = stack_init(numbers, 5);
	b = stack_init(num, 3);
	print_stack(a);
	print_stack(b);

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

	printf("After reverse rotate a : \n");
	rra(&a);
	rrb(&b);
	rrr(&a, &b);

	print_stack(a);
	print_stack(b);
	stack_clear(&a);
	stack_clear(&b);
}