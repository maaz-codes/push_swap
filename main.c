/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:33:13 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 17:14:03 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	t_stack_clear(t_stack **a)
{
	t_stack	*block;

	while (*a != NULL)
	{
		block = (*a);
		*a = (*a)->next;
		free(block);
	}
}

void	free_strings(char *big_arg, char **nums)
{
	int	i;

	i = 0;
	while (i < ft_word_count(big_arg, ' '))
	{
		free(nums[i]);
		i++;
	}
	free(big_arg);
	free(nums);
}

char	*arg_join(int argc, char **argv)
{
	char	*big_arg;
	char	*temp_arg;
	int		i;
	char	**nums;

	big_arg = ft_strdup(" ");
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(ft_strtrim(argv[i], " ")) == 0)
		{
			free(big_arg);
			return (NULL);
		}
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

char	*parsing(t_stack **a, int argc, char **argv)
{
	char	**nums;
	char	*big_arg;

	big_arg = arg_join(argc, argv);
	if (!big_arg)
		return (NULL);
	nums = ft_split(big_arg, ' ');
	if (!nums)
		return (NULL);
	if (!t_stack_init(a, nums, ft_word_count(big_arg, ' ')))
	{
		free_strings(big_arg, nums);
		return (NULL);
	}
	free_strings(big_arg, nums);
	return ("SUCESS");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**nums;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc > 1)
	{
		if (!parsing(&a, argc, argv))
			return (error_msg(&a, &b));
		if (!is_sorted(a))
			sorting(&a, &b);
		else
		{
			t_stack_clear(&a);
			t_stack_clear(&b);
			return (0);
		}
	}
	t_stack_clear(&a);
	t_stack_clear(&b);
}
