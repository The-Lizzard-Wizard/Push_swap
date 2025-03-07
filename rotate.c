/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:37 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/06 11:43:16 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate_a(t_stack **root_a)
{
	*root_a = (*root_a)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_stack **root_b)
{
	*root_b = (*root_b)->next;
	ft_printf("rb\n");
}

void	rotate_r(t_stack **root_a, t_stack **root_b)
{
	ft_printf("rr\n");
	rotate_a(root_a);
	rotate_b(root_b);
}
