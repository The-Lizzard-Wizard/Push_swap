/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <amog_sus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:54:15 by ********          #+#    #+#             */
/*   Updated: 2025/03/06 11:43:51 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	int				normal;
	char			*bin;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/*========================================*/
/*=        struct manipulation           =*/
/*========================================*/

t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **node, t_stack *new_node);
void	ft_stackadd_back(t_stack *node, t_stack *new_node);
int		ft_stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	normal(t_stack *stack);
int		init(t_stack *stack);
int		ft_atol(const char *nptr, t_stack *stack);

/*========================================*/
/*=                 sort                 =*/
/*========================================*/

int		is_sort(t_stack *root);
int		is_reverse_sort(t_stack *root);
void	sort(t_stack **root_a, t_stack **root_b);

/*========================================*/
/*=             error check              =*/
/*========================================*/

int		check_error(int argc, char **argv);
char	**pars_one_arg(char *one_long_arg);
void	exit_error(t_stack *stack, const char *ms);

/*========================================*/
/*=          push swap function          =*/
/*========================================*/

void	push_a(t_stack **root_b, t_stack **root_a);
void	push_b(t_stack **root_a, t_stack **root_b);
void	reverse_a(t_stack **root_a);
void	reverse_b(t_stack **root_b);
void	reverse_rr(t_stack **root_a, t_stack **root_b);
void	rotate_a(t_stack **root_a);
void	rotate_b(t_stack **root_b);
void	rotate_r(t_stack **root_a, t_stack **root_b);
void	swap(t_stack *root);
void	swap_a(t_stack *root_a);
void	swap_b(t_stack *root_b);
void	swap_s(t_stack *root_a, t_stack *root_b);

#endif
