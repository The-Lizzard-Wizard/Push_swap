/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:29 by ********          #+#    #+#             */
/*   Updated: 2025/03/04 17:37:04 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_node;

	new_node = NULL;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->bin = NULL;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

void	ft_stackadd_front(t_stack **node, t_stack *new_node)
{
	if (!node || !new_node)
		return ;
	(*node)->prev->next = new_node;
	new_node->prev = (*node)->prev;
	(*node)->prev = new_node;
	new_node->next = *node;
	*node = new_node;
}

void	ft_stackadd_back(t_stack *node, t_stack *new_node)
{
	if (!node || !new_node)
		return ;
	node->prev->next = new_node;
	new_node->prev = node->prev;
	node->prev = new_node;
	new_node->next = node;
}

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*root;

	root = stack;
	size = 1;
	if (!root)
		return (0);
	while (stack->next != root)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
