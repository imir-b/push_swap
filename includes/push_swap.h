/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:18:18 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/30 03:29:23 by vbleskin         ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// PARSING
int			ft_init_stack(t_stack **stack_a, int ac, char **av);
int			ft_parsing(t_stack **stack_a, char **args);
int			ft_check_duplicate(t_stack *stack_a);
int			ft_check_args(char **args);
// ERRORS
void		ft_error(void);
void		ft_free_stack(t_stack **stack);
void		ft_free(char **args);
// UTILS
long int	ft_atol(char *nb);
void		ft_stackaddback(t_stack **stack, t_stack *new);
t_stack		*ft_stacknew(int nb);

#endif