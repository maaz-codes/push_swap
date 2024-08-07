#include "pushswap.h"

stack *stack_new(int number)
{
    stack *block;

    block = malloc(sizeof(stack));
    if (!block)
        return (NULL);
    block->content = number;
	block->prev = NULL;
    block->next = NULL;

    return (block);
}

stack *last_block(stack *a)
{
    stack *block;

    block = a;
    if (block == NULL)
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
		new_block->prev = block;
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

stack *stack_init(int *numbers, int len)
{
    stack *a;
    int i;

    i = 0;
    a = NULL;
    while (i < len)
    {
	    stack_add(&a, stack_new(numbers[i]));
        i++;
    }
    return (a);
}


//to remove ---------------------------------------------------

void print_stack(stack *a)
{
	stack *block;

	block = a;
	while (block != NULL)
	{
		// printf("%p ", block->prev);
		printf("%d \n", block->content);
		// printf("%p ", block->next);
        // printf("\n");
		block = block->next;
	}
	printf("\n");
}

void del_block(stack *a)
{
	a->prev = NULL;
	a->prev = NULL;
    free(a);
}

void stack_clear(stack **a)
{
    stack *block;
    while (*a != NULL)
    {
        block = (*a)->next;
        del_block(*a);
        *a = block; 
    }
    *a = NULL;
}