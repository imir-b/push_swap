/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:27:39 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/10 14:25:15 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate(int nb, t_stack *b)
{
	(void)nb;
	(void)b;
	return (0);
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
		cur_count = ft_calculate(current->number, b);
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
