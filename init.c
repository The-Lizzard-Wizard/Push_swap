/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:49:55 by ********          #+#    #+#             */
/*   Updated: 2025/03/04 14:21:26 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	normal(t_stack *stack)
{
	t_stack	*root;
	t_stack	*stack2;
	int		index;
	int		b_1;
	int		b_2;

	stack2 = stack;
	root = stack;
	b_1 = 0;
	while (b_1 == 0 || stack != root)
	{
		index = 1;
		stack2 = root;
		b_2 = 0;
		while (b_2 == 0 || stack2 != root)
		{
			b_2 = 1;
			if (stack2->content < stack->content)
				index++;
			stack2 = stack2->next;
		}
		stack->normal = index;
		stack = stack->next;
		b_1 = 1;
	}
}

char	*convert_base(int nbr, const char *base)
{
	char	*res;
	size_t	i;

	res = NULL;
	i = 0;
	res = ft_strdup("00000000000000000000000000000000");
	if (!res)
		return (NULL);
	if (nbr == 0)
		res[i++] = '0';
	else
	{
		while (nbr > 0)
		{
			res[i++] = base[nbr % ft_strlen(base)];
			nbr /= ft_strlen(base);
		}
	}
	return (res);
}

int	init(t_stack *stack)
{
	int		b_1;
	t_stack	*root;

	root = stack;
	b_1 = 0;
	normal(stack);
	while (b_1 == 0 || stack != root)
	{
		stack->bin = convert_base(stack->normal, "01");
		if (!stack->bin)
			return (0);
		stack = stack->next;
		b_1 = 1;
	}
	return (1);
}
