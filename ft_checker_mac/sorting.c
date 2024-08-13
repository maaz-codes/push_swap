#include "checker.h"

int is_sorted(stack *a, stack *b)
{
	if (b != NULL)
		return (0);
	while (a)
	{
		if (a->next)
			if (a->content > a->next->content)
				return (0);
		a = a->next;
	}
	return (1);
}