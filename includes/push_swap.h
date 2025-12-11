/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:18:18 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/11 06:54:19 by vlad             ###   ########.fr       */
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
t_stack		*ft_find_target(t_stack *current, t_stack *stack_b);
void		ft_sort_three(t_stack **a);
void		ft_push_back(t_stack **a, t_stack **b);
int			ft_calculate(t_stack *current, t_stack *a, t_stack *b);
// TEST
void		ft_put_stack(t_stack *stack, char c);
#endif