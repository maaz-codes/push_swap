/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:30:17 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 15:30:34 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	reverse_rotate_ab(stack **a, stack **b, stack *cheapest, stack *target)
{
	rrr(a, b);
	cheapest->index_to_top++;
	target->index_to_top++;
}

void	rotate_a(stack **a, stack *target)
{
	ra(a);
	target->index_to_top--;
}

void	reverse_rotate_a(stack **a, stack *target)
{
	rra(a);
	target->index_to_top++;
}

void	rotate_b(stack **b, stack *cheapest)
{
	rb(b);
	cheapest->index_to_top--;
}

void	reverse_rotate_b(stack **b, stack *cheapest)
{
	rrb(b);
	cheapest->index_to_top++;
}
