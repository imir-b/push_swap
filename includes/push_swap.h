/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:18:18 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 01:42:46 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				is_reverse;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// PARSING
int			ft_init_stack(t_stack **stack_a, int ac, char **av);
int			ft_parsing(t_stack **stack_a, char **args);
int			ft_check_duplicate(t_stack *stack_a);
int			ft_check_args(char **args);
// ERROR & FREE
void		ft_error(void);
void		ft_free_stack(t_stack **stack);
void		ft_free_split(char **args);
// UTILS
long int	ft_atol(char *nb);
void		ft_stackaddback(t_stack **stack, t_stack *new);
t_stack		*ft_stacknew(int nb);
int			ft_stacksize(t_stack *stack);
void		ft_set_index(t_stack *stack);
// ALGO
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
t_stack		*ft_find_cheapest(t_stack *a, t_stack *b);
t_stack		*ft_find_target_b(t_stack *node, t_stack *stack_b);
t_stack		*ft_find_max(t_stack *stack);
t_stack		*ft_find_target_a(t_stack *node, t_stack *stack_a);
t_stack		*ft_find_min(t_stack *stack);
void		ft_sort_three(t_stack **a);
int			ft_get_cost(t_stack *node, t_stack *stack);
int			ft_get_total_cost(t_stack *current, t_stack *a, t_stack *b);
void		ft_move_nodes(t_stack *node, t_stack *target, t_stack **a, t_stack **b);
void		ft_push_back(t_stack **b, t_stack **a);
// TEST
void		ft_put_stack(t_stack *stack, char c);
#endif