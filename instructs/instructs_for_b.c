/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_for_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:28:47 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 15:28:51 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sb(stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	pb(stack **b, stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	rb(stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rrb(stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
