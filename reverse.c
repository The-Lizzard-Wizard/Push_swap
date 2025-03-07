/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:40 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/06 11:43:37 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	reverse_a(t_stack **root_a)
{
	*root_a = (*root_a)->prev;
	ft_printf("rra\n");
}

void	reverse_b(t_stack **root_b)
{
	*root_b = (*root_b)->prev;
	ft_printf("rrb\n");
}

void	reverse_rr(t_stack **root_a, t_stack **root_b)
{
	ft_printf("rrr\n");
	reverse_a(root_a);
	reverse_b(root_b);
}
