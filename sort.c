/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:59:03 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/06 11:43:03 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	sort_three(t_stack **root_a)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *root_a;
	node2 = (*root_a)->next;
	node3 = (*root_a)->prev;
	if (node3->normal != 3)
	{
		if (node1->normal == 3)
			rotate_a(root_a);
		else
			reverse_a(root_a);
	}
	if ((*root_a)->normal > (*root_a)->next->normal)
		swap_a(*root_a);
}

void	sort_four_five(t_stack **root_a, t_stack **root_b)
{
	while (ft_stack_size(*root_b) < 2)
	{
		if ((*root_a)->normal == 1 || (*root_a)->normal == 2)
			push_b(root_a, root_b);
		else
			reverse_a(root_a);
	}
	if ((*root_b)->normal < (*root_b)->next->normal)
		swap_b(*root_b);
	if ((*root_a)->prev->normal != 5)
	{
		if ((*root_a)->normal == 5)
			rotate_a(root_a);
		else
			reverse_a(root_a);
	}
	if ((*root_a)->normal > (*root_a)->next->normal)
		swap_a(*root_a);
	push_a(root_b, root_a);
	push_a(root_b, root_a);
}

void	radix_b(t_stack **root_a, t_stack **root_b, size_t i)
{
	int	size;

	size = ft_stack_size(*root_b);
	while (size > 0)
	{
		if ((*root_b)->bin[i] == '1')
			push_a(root_b, root_a);
		else if (!is_reverse_sort(*root_b))
			rotate_b(root_b);
		size--;
	}
}

void	radix(t_stack **root_a, t_stack **root_b)
{
	size_t	i;
	int		size;

	size = ft_stack_size(*root_a);
	i = 0;
	while (i < 32 && !is_sort(*root_a))
	{
		size = ft_stack_size(*root_a);
		while (size > 0 && !is_sort(*root_a))
		{
			if ((*root_a)->bin[i] == '0')
				push_b(root_a, root_b);
			else
				rotate_a(root_a);
			size--;
		}
		i++;
		radix_b(root_a, root_b, i);
	}
	while (ft_stack_size(*root_b) > 0)
		push_a(root_b, root_a);
}

void	sort(t_stack **root_a, t_stack **root_b)
{
	if (ft_stack_size(*root_a) == 2)
	{
		if ((*root_a)->normal > (*root_a)->next->normal)
			swap_a(*root_a);
	}
	else if (ft_stack_size(*root_a) == 3)
		sort_three(root_a);
	else if (ft_stack_size(*root_a) == 4 || ft_stack_size(*root_a) == 5)
		sort_four_five(root_a, root_b);
	else if (ft_stack_size(*root_a) > 5)
		radix(root_a, root_b);
}
