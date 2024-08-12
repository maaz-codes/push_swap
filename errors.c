/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:58 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 17:00:39 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	error_msg(t_stack **a, t_stack **b)
{
	t_stack_clear(a);
	t_stack_clear(b);
	write(1, "Error\n", 6);
	return (0);
}

char	*repetition_error(t_stack **a, long number)
{
	t_stack	*block;

	block = (*a);
	while (block)
	{
		if (block->content == number)
			return (NULL);
		block = block->next;
	}
	return ("No repetition");
}
