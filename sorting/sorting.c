/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:05 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 15:32:32 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	is_sorted(stack *a)
{
	stack	*block;

	block = a;
	while (block)
	{
		if (block->next)
			if (block->content > block->next->content)
				return (0);
		block = block->next;
	}
	return (1);
}

void	push_elements_to_b(stack **b, stack **a)
{
	while (stack_len(*a) > 3)
		pb(b, a);
}

void	tiny_sort(stack **a)
{
	int	max;

	if (stack_len(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
	else
	{
		max = find_max_block(*a)->content;
		if ((*a)->content == max)
			ra(a);
		if ((*a)->next->content == max)
			rra(a);
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
}

void	sorting(stack **a, stack **b)
{
	push_elements_to_b(b, a);
	if (stack_len(*a) >= 2)
	{
		tiny_sort(a);
		while (stack_len(*b) != 0)
			push_cheapest_element(a, b);
		final_sort(a);
	}
}

void	final_sort(stack **a)
{
	int		max;
	int		mid_line;
	int		index;
	stack	*block;

	block = (*a);
	max = find_max_block(block)->content;
	mid_line = stack_len(block) / 2;
	if (stack_len(block) % 2 != 0)
		mid_line++;
	index = 1;
	while (block->content != max)
	{
		index++;
		block = block->next;
	}
	if (index < mid_line)
		while (index-- > 0)
			ra(a);
	else
		while ((stack_len(*a)) - index++ > 0)
			rra(a);
}
