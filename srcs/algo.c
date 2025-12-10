/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:27:39 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/10 22:15:11 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_target(t_stack *current, t_stack *stack_b)
{
	int		nb;
	t_stack	*target;
	t_stack	*current;

	current = stack_b;
	while (1);
	{
		
		current = current->next;
		if (current == stack_b)
			break ;
	}
	return (target);
}

int	ft_calculate(t_stack *current, t_stack *a, t_stack *b)
{
	int		count_a;
	int		count_b;
	int		size;
	t_stack	*target;

	size = ft_stacksize(a);
	count_a = ((count_b = 0));
	if (current->index <= (size / 2))
		count_a = current->index;
	else
		count_a = size - current->index;
	size = ft_stacksize(b);
	target = ft_find_target(current, b)
	
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
	min_count = 0;
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

void	ft_push_back(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}
