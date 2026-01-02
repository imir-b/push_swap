/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:52:02 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 04:48:33 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_stack **a, int print)
{
	ft_rotate(a);
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack **b, int print)
{
	ft_rotate(b);
	if (print)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, PRINT_N);
	rb(b, PRINT_N);
	if (print)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
