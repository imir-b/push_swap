/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_get_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:59:34 by vlad              #+#    #+#             */
/*   Updated: 2025/12/12 14:59:42 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_cost(t_stack *node, t_stack *stack)
{
	int	cost;
	int	size;

	size = ft_stacksize(stack);
	cost = 0;
	if (node->index <= (size / 2))
	{
		node->is_reverse = 0;
		cost = node->index;
	}
	else
	{
		node->is_reverse = 1;
		cost = size - node->index;
	}
	return (cost);
}

int	ft_get_total_cost(t_stack *current, t_stack *a, t_stack *b)
{
	int		count_a;
	int		count_b;
	t_stack	*target;

	target = current->target;
	count_a = ft_get_cost(current, a);
	count_b = ft_get_cost(target, b);
	if (target->is_reverse == current->is_reverse)
	{
		if (count_a > count_b)
			return (count_a);
		return (count_b);
	}
	else
		return (count_a + count_b);
}
