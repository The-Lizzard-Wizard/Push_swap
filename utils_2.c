/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:40:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/04 14:54:38 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_sort(t_stack *root)
{
	int	i;

	i = 0;
	while (i < ft_stack_size(root) - 1)
	{
		if (root->normal > root->next->normal)
			return (0);
		root = root->next;
		i++;
	}
	return (1);
}

int	is_reverse_sort(t_stack *root)
{
	int	i;

	i = ft_stack_size(root) - 1;
	while (i > 0)
	{
		if (root->normal < root->next->normal)
			return (0);
		root = root->next;
		i--;
	}
	return (1);
}

void	exit_error(t_stack *stack, const char *ms)
{
	free_stack(stack);
	ft_printf(ms);
	exit(1);
}

int	ft_atol(const char *nptr, t_stack *stack)
{
	size_t			i;
	long int		s;
	long long int	n;

	i = 0;
	n = 0;
	s = 1;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		s = s * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		if ((n) > 2147483647 || (n * s) < -2147483648)
			exit_error(stack, "Error\n");
		i++;
	}
	return ((int)(n * s));
}
