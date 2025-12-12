/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:27:39 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 13:19:07 by vlad             ###   ########.fr       */
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

void	ft_sort_three(t_stack **a)
{
	const int	first = (*a)->number;
	const int	second = (*a)->next->number;
	const int	last = (*a)->prev->number;

	if (ft_stacksize(*a) != 3)
		return ;
	if (first < second && first > last)
		return (rra(a));
	if (first < second && second > last)
		return (rra(a), sa(a));
	if (first > second && second > last)
		return (sa(a), rra(a));
	if (first > second && first < last)
		return (sa(a));
	if (first > second && second < last)
		return (ra(a));
}

void	ft_move_nodes(t_stack *node, t_stack *target, t_stack **a, t_stack **b)
{
	if ((node->is_reverse == target->is_reverse) == 1)
	{
		while (*b != target && *a != node)
			rr(a, b);
	}
	else if ((node->is_reverse == target->is_reverse) == 0)
	{
		while (*b != target && *a != node)
			rrr(a, b);
	}
	while (*b != target)
	{
		if (target->is_reverse)
			rrb(b);
		else
			rb(b);
	}
	while (*a != node)
	{
		if (node->is_reverse)
			rra(a);
		else
			ra(a);
	}
}

void	ft_push_back(t_stack **b, t_stack **a)
{
	t_stack	*target_a;

	while (*b)
	{
		ft_set_index(*a);
		ft_set_index(*b);
		target_a = ft_find_target_a(*b, *a);
		if (target_a->index <= ft_stacksize(*a) / 2)
		{
        	while (*a != target_a)
				ra(a);
		}
		else
		{
			while (*a != target_a)
				rra(a);
		}
		pa(a, b);
	}
}