/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:09 by ********          #+#    #+#             */
/*   Updated: 2025/03/06 11:39:32 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*push_node;

	push_node = *from;
	if (ft_stack_size(*from) > 1)
	{
		push_node->prev->next = push_node->next;
		push_node->next->prev = push_node->prev;
		*from = push_node->next;
	}
	else
		*from = NULL;
	if (!*to)
	{
		*to = push_node;
		(*to)->next = *to;
		(*to)->prev = *to;
	}
	else
		ft_stackadd_front(to, push_node);
}

void	push_a(t_stack **root_b, t_stack **root_a)
{
	push(root_b, root_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **root_a, t_stack **root_b)
{
	push(root_a, root_b);
	ft_printf("pb\n");
}
