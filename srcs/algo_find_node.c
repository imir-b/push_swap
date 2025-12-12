/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_find_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:49:24 by vlad              #+#    #+#             */
/*   Updated: 2025/12/12 14:50:24 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*tmp;

	tmp = stack;
	max = stack->next;
	while (1)
	{
		if (max->number < tmp->number)
			max = tmp;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (max);
}

t_stack	*ft_find_target_b(t_stack *node, t_stack *stack_b)
{
	long	best;
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = stack_b;
	best = LONG_MIN;
	while (1)
	{
		if (tmp->number < node->number && tmp->number > best)
		{
			best = tmp->number;
			target = tmp;
		}
		tmp = tmp->next;
		if (tmp == stack_b)
			break ;
	}
	if (best == LONG_MIN)
		target = ft_find_max(stack_b);
	return (target);
}

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	tmp = stack;
	min = stack->next;
	while (1)
	{
		if (min->number > tmp->number)
			min = tmp;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (min);
}

t_stack	*ft_find_target_a(t_stack *node, t_stack *stack_a)
{
	long	best;
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = stack_a;
	best = LONG_MAX;
	while (1)
	{
		if (tmp->number > node->number && tmp->number < best)
		{
			best = tmp->number;
			target = tmp;
		}
		tmp = tmp->next;
		if (tmp == stack_a)
			break ;
	}
	if (best == LONG_MAX)
		target = ft_find_min(stack_a);
	return (target);
}

t_stack	*ft_find_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*current;
	long	min_count;
	long	cur_count;

	if (!a)
		return (NULL);
	current = a;
	cheapest = NULL;
	min_count = LONG_MAX;
	while (1)
	{
		current->target = ft_find_target_b(current, b);
		cur_count = ft_get_total_cost(current, a, b);
		if (cur_count < min_count)
		{
			min_count = cur_count;
			cheapest = current;
		}
		current = current->next;
		if (current == a)
			break ;
	}
	return (cheapest);
}
