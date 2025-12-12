/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:52:06 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 14:26:12 by vlad             ###   ########.fr       */
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

void	sa(t_stack **a, int print)
{
	ft_swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int print)
{
	ft_swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
