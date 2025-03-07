/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:22:31 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/07 12:40:30 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	check_digit(char *str)
{
	size_t	index;

	index = 0;
	if (str[index] == '-' && (str[index + 1] < '0' || str[index + 1] > '9'))
		return (1);
	if ((str[index] < '0' || str[index] > '9') && str[index] != '-')
		return (1);
	else
		index++;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
			return (1);
		index++;
	}
	return (0);
}

static int	check_double(int argc, char **argv)
{
	int	index_1;
	int	index_2;

	index_1 = 1;
	while (index_1 < argc)
	{
		index_2 = index_1 + 1;
		while (index_2 < argc)
		{
			if (ft_atoi(argv[index_1]) == ft_atoi(argv[index_2]))
				return (1);
			index_2++;
		}
		index_1++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	size_t	index;

	while (argc > 1)
	{
		index = argc - 2;
		if (check_double(argc, argv) || check_digit(argv[argc - 1]))
			return (1);
		argc--;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*root;
	t_stack	*del_node;
	int		size;
	int		i;

	size = ft_stack_size(stack);
	i = 0;
	root = stack;
	if (!root)
		return ;
	while (i < size)
	{
		del_node = stack;
		stack = stack->next;
		free(del_node->bin);
		free(del_node);
		i++;
	}
}
