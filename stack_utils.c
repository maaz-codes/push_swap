#include "pushswap.h"

stack *stack_new(int number)
{
    stack *block;

    block = malloc(sizeof(stack));
    if (!block)
        return (NULL);
    block->content = number;
    block->index_to_top = 0;
    block->next = NULL;
    return (block);
}

stack *last_block(stack *a)
{
    stack *block;

    block = a;
    if (!block)
        return (NULL);
    while (block->next != NULL)
        block = block->next;
    return (block);
}

void stack_add(stack **a, stack *new_block)
{
	stack *block;

	if(!a)
		return ;
	if (*a == NULL)
	{
		if (!new_block)
			return ;
		*a = new_block;
	}
	else
	{
		block = last_block(*a);
		block->next = new_block;
	}
}

int stack_len(stack *a)
{
    int     len;
    stack   *ptr;

    len = 0;
    ptr = a;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    return (len);
}

char *stack_init(stack **a, char **strings, int len)
{
	int i;
	long long number;

	i = 0;
	number = 0;
	
	while (i < len)
    {
		if (!ft_atol_modified(strings[i], &number))
			return (NULL);
		if (!repetition_error(a, number))
			return (NULL);
	    stack_add(a, stack_new(number));
        i++;
    }
    return ("Initialised");
}

void stack_clear(stack **a)
{
    stack *block;

    while (*a != NULL)
    {
        block = (*a);
        *a = (*a)->next;
        free(block); 
    }
}

//to remove ---------------------------------------------------

void print_stack(stack *a)
{
	stack *block;

	block = a;
	while (block != NULL)
	{
		printf("%d ", block->content);
		block = block->next;
	}
    printf("\n");
}