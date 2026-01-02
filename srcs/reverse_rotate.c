/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:51:59 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 04:48:51 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_stack **a, int print)
{
	ft_reverse_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack **b, int print)
{
	ft_reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, PRINT_N);
	rrb(b, PRINT_N);
	if (print)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
