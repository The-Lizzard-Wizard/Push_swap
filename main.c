/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <****************.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:53:44 by ********          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:23 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	store_stack(int argc, char **argv, t_stack **root_a)
{
	int		index;
	t_stack	*new_node;

	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			if (index == 1)
			{
				*root_a = ft_stacknew(ft_atol(argv[index], *root_a));
				if (!root_a)
					return (0);
			}
			else
			{
				new_node = ft_stacknew(ft_atol(argv[index], *root_a));
				if (!new_node)
					return (0);
				ft_stackadd_back(*root_a, new_node);
			}
			index++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*root_a;
	t_stack	*root_b;

	root_a = NULL;
	root_b = NULL;
	if (argc < 2)
		return (0);
	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (store_stack(argc, argv, &root_a) == 0)
		return (free_stack(root_a), 0);
	if (init(root_a) == 0)
		return (free_stack(root_a), 0);
	if (is_sort(root_a))
		exit_error(root_a, "");
	sort(&root_a, &root_b);
	free_stack(root_a);
	free_stack(root_b);
	return (0);
}
