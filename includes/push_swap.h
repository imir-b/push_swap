/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:18:18 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 04:52:59 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define SUCCESS 0
# define ERROR 1
# define PRINT_Y 1
# define PRINT_N 0
# define TRUE 1
# define FALSE 0

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
int			ft_parsing(t_stack **stack_a, char **args);
int			ft_check_duplicate(t_stack *stack_a);
int			ft_check_args(char **args);
// ERROR & FREE
int			ft_error(void);
void		ft_free_stack(t_stack **stack);
void		ft_free_split(char **args);
// UTILS
long int	ft_atol(char *nb);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_is_sorted(t_stack *stack);
// STACK UTILS
void		ft_stackaddback(t_stack **stack, t_stack *new);
t_stack		*ft_stacknew(int nb);
int			ft_stacksize(t_stack *stack);
void		ft_set_index(t_stack *stack);
int			ft_init_stack(t_stack **stack_a, int ac, char **av);
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
void		ft_push_swap(t_stack **a, t_stack **b, int print);
// DEBUG
//void		ft_put_stack(t_stack *stack, char c);
#endif