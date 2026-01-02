/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:27:39 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 05:45:59 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Fonction qui trie une stack de 3 nombres, on l'utilise quand on a plus que 
 * 3 nombres dans 'a', on a 5 cas possibles avec un max de 2 operations.
 */
void	ft_sort_three(t_stack **a, int print)
{
	const int	first = (*a)->number;
	const int	second = (*a)->next->number;
	const int	last = (*a)->prev->number;

	if (ft_stacksize(*a) != 3)
		return ;
	if (first < second && first > last)
		return (rra(a, print));
	if (first < second && second > last)
		return (rra(a, print), sa(a, print));
	if (first > second && second > last)
		return (sa(a, print), rra(a, print));
	if (first > second && first < last)
		return (sa(a, print));
	if (first > second && second < last)
		return (ra(a, print));
}

/**
 * Fonction qui deplace 'node' et sa cible 'node->target' en haut de leurs stack
 * respectives en utilisant le moins de coups possibles.
 */
void	ft_move_nodes(t_stack *node, t_stack **a, t_stack **b, int print)
{
	if ((node->is_reverse == TRUE) && (node->target->is_reverse == TRUE))
	{
		while (*b != node->target && *a != node)
			rrr(a, b, print);
	}
	else if ((node->is_reverse == FALSE) && (node->target->is_reverse == FALSE))
	{
		while (*b != node->target && *a != node)
			rr(a, b, print);
	}
	while (*b != node->target)
	{
		if (node->target->is_reverse)
			rrb(b, print);
		else
			rb(b, print);
	}
	while (*a != node)
	{
		if (node->is_reverse)
			rra(a, print);
		else
			ra(a, print);
	}
}

/**
 * Fonction qui remet les noeuds de 'b' dans 'a' une fois dans le
 * bon ordre.
 */
void	ft_push_back(t_stack **b, t_stack **a, int print)
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
				ra(a, print);
		}
		else
		{
			while (*a != target_a)
				rra(a, print);
		}
		pa(a, b, print);
	}
}

/**
 * Remet le plus petit nombre de 'a' en haut de la stack.
 */
void	ft_align_stack(t_stack **a, int print)
{
	t_stack	*min;

	ft_set_index(*a);
	min = ft_find_min(*a);
	while (*a != min)
	{
		if (min->index <= ft_stacksize(*a) / 2)
			ra(a, print);
		else
			rra(a, print);
	}
}

/**
 * Fonction qui gere tout l'algo de trie.
 */
void	ft_push_swap(t_stack **a, t_stack **b, int print)
{
	t_stack	*cheapest;

	cheapest = NULL;
	if (ft_stacksize(*a) == 2 && (*a)->number > (*a)->next->number)
		sa(a, print);
	if (ft_stacksize(*a) <= 2)
		return ;
	if (ft_stacksize(*a) > 3 && !*b)
		pb(b, a, print);
	if (ft_stacksize(*a) > 3 && !(*b)->next)
		pb(b, a, print);
	while (ft_stacksize(*a) > 3)
	{
		ft_set_index(*a);
		ft_set_index(*b);
		cheapest = ft_find_cheapest(*a, *b);
		ft_get_total_cost(cheapest, *a, *b);
		ft_move_nodes(cheapest, a, b, print);
		pb(b, a, print);
	}
	ft_sort_three(a, print);
	ft_push_back(b, a, print);
	ft_align_stack(a, print);
}
