/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:27 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/06 11:42:47 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_stack *root)
{
	int		tmp_content;
	int		tmp_normal;
	char	*tmp_bin;

	tmp_content = root->next->content;
	tmp_normal = root->next->normal;
	tmp_bin = root->next->bin;
	root->next->content = root->content;
	root->next->normal = root->normal;
	root->next->bin = root->bin;
	root->content = tmp_content;
	root->normal = tmp_normal;
	root->bin = tmp_bin;
}

void	swap_a(t_stack *root_a)
{
	swap(root_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *root_b)
{
	swap(root_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack *root_a, t_stack *root_b)
{
	ft_printf("ss\n");
	swap_a(root_a);
	swap_b(root_b);
}
