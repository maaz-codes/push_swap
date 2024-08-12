#include "pushswap.h"

void free_strings(char *big_arg, char **nums)
{
	int i;

	i = 0;
	while (i < ft_word_count(big_arg, ' '))
	{
		free(nums[i]);
		i++;
	}
	free(big_arg);
	free(nums);
}

char *arg_join(int argc, char **argv)
{
	char *big_arg;
	char *temp_arg;
	int i;
	char **nums;

	big_arg = ft_strdup(" ");
	i = 1;
	while (i < argc)
	{	
		temp_arg = big_arg;
		big_arg = ft_strjoin(big_arg, argv[i]);
		free(temp_arg);
		temp_arg = big_arg;
		big_arg = ft_strjoin(big_arg, " ");
		free(temp_arg);
		i++;
	}
	return (big_arg);
}

char *parsing(stack **a, int argc, char **argv)
{
	char **nums;
	char *big_arg;

	big_arg = arg_join(argc, argv);  
	if (!big_arg)
		return (NULL);
	nums = ft_split(big_arg, ' ');
	if (!nums)
		return (NULL);
	if(!stack_init(a, nums, ft_word_count(big_arg, ' ')))
	{
		free_strings(big_arg, nums);
		return (NULL);
	}
	free_strings(big_arg, nums);
	return ("SUCESS");
} 
int	main(int argc, char *argv[])
{
    stack *a;
	stack *b;
	char **nums;
	int i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc > 1)
	{	
		if (!parsing(&a, argc, argv))
			return (error_msg());
		if (!is_sorted(a))
			sorting(&a, &b);
		else
		{
			stack_clear(&a);
			stack_clear(&b);
			return (0);
		}
		print_stack(a);
	}
	stack_clear(&a);
	stack_clear(&b);
}
