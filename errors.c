/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:58 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 15:33:09 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	error_msg(stack **a, stack **b)
{
	stack_clear(a);
	stack_clear(b);
	write(1, "Error\n", 6);
	return (0);
}

char	*repetition_error(stack **a, long number)
{
	stack	*block;

	block = (*a);
	while (block)
	{
		if (block->content == number)
			return (NULL);
		block = block->next;
	}
	return ("No repetition");
}
