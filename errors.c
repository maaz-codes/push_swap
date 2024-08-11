#include "pushswap.h"

int error_msg()
{
	write (1, "Error\n", 6);
	return 0;
}

char *repetition_error(stack **a, long number)
{
	stack *block;

	block = (*a);
	while (block)
	{
		if (block->content == number)
			return (NULL);
		block = block->next;
	}
	return ("No repetition");
}