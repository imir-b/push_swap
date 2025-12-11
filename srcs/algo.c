/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:27:39 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/11 07:21:03 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_target(t_stack *current, t_stack *stack_b)
{
	int		nb;
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = stack_b;
	while (1)
	{
		nb = tmp->number;
		if ((current->number < nb) && (!target || target->number < nb))
			target = tmp;
		tmp = tmp->next;
		if (tmp == stack_b)
			break ;
	}
	return (target);
}

int	ft_calculate(t_stack *current, t_stack *a, t_stack *b) //prendre en compte rr et rrr
{
	int		count_a;
	int		count_b;
	int		size;
	t_stack	*target;

	size = ft_stacksize(a);
	count_a = 0;
	if (current->index <= (size / 2))
		count_a = current->index;
	else
		count_a = size - current->index;
	size = ft_stacksize(b);
	count_b = 0;
	target = ft_find_target(current, b);
	if (target->index <= (size / 2))
		count_b = target->index;
	else
		count_b = size - target->index;
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
		cur_count = ft_calculate(current, a, b);
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

}

void	ft_push_back(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}
