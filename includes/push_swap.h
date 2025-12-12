/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:18:18 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 14:48:43 by vlad             ###   ########.fr       */
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
// PUSH
void		pa(t_stack **a, t_stack **b, int print);
void		pb(t_stack **b, t_stack **a, int print);
// SWAP
void		sa(t_stack **a, int print);
void		sb(t_stack **b, int print);
void		ss(t_stack **a, t_stack **b, int print);
// ROTATE
void		ra(t_stack **a, int print);
void		rb(t_stack **b, int print);
void		rr(t_stack **a, t_stack **b, int print);
// REVERSE ROTATE
void		rra(t_stack **a, int print);
void		rrb(t_stack **b, int print);
void		rrr(t_stack **a, t_stack **b, int print);
// ALGO
t_stack		*ft_find_cheapest(t_stack *a, t_stack *b);
t_stack		*ft_find_target_b(t_stack *node, t_stack *stack_b);
t_stack		*ft_find_max(t_stack *stack);
t_stack		*ft_find_target_a(t_stack *node, t_stack *stack_a);
t_stack		*ft_find_min(t_stack *stack);
int			ft_get_cost(t_stack *node, t_stack *stack);
int			ft_get_total_cost(t_stack *current, t_stack *a, t_stack *b);
void		ft_sort_three(t_stack **a, int print);
void		ft_move_nodes(t_stack *node, t_stack **a, t_stack **b, int print);
void		ft_push_back(t_stack **b, t_stack **a, int print);
void		ft_align_stack(t_stack **a, int print);
void		ft_algo(t_stack **a, t_stack **b);
// TEST
void		ft_put_stack(t_stack *stack, char c);
#endif