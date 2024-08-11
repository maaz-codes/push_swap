#include "pushswap.h"

int	main(int argc, char *argv[])
{
    stack *a;
	stack *b;
	int total_numbers;
	char **nums;
	int i;

	total_numbers = argc - 1;
	a = NULL;
	b = NULL;
	if (argc > 1 && argc < ARG_MAX)
	{
		if (argc == 2)
		{
			nums = ft_split(argv[1], ' ');
			total_numbers = ft_word_count(argv[1], ' ');
		}
		else
			nums = argv + 1;
		i = 0;
		if(!stack_init(&a, nums, total_numbers))
			return (error_msg());
		if (!is_sorted(a))
			sorting(&a, &b);
		else
			printf("Already sorted!");
		print_stack(a);
		stack_clear(&a);
		stack_clear(&b);
	}
}
