/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:52:06 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/30 05:04:41 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	tmp = first->number;
	first->number = second->number;
	second->number = tmp;
}

void	sa(t_stack **a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}
