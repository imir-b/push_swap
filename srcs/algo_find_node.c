/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_find_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:49:24 by vlad              #+#    #+#             */
/*   Updated: 2026/01/02 05:10:14 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Fonction qui retourne le noeud avec le plus grand nombre de la 'stack'
 */
t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*tmp;

	tmp = stack;
	max = stack->next;
	while (TRUE)
	{
		if (max->number < tmp->number)
			max = tmp;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (max);
}

/**
 * Fonction qui retourne le noeud cible dans 'stack_b' qui devra
 * arriver juste en dessous de 'node'
 */
t_stack	*ft_find_target_b(t_stack *node, t_stack *stack_b)
{
	long	best;
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = stack_b;
	best = LONG_MIN;
	while (TRUE)
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

/**
 * Fonction qui retourne le noeud avec le plus petit nombre de la 'stack'
 */
t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	tmp = stack;
	min = stack->next;
	while (TRUE)
	{
		if (min->number > tmp->number)
			min = tmp;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (min);
}

/**
 * Fonction qui retourne le noeud de 'b' qui prendra le moins de coups a trier
 * dans 'a'.
 */
t_stack	*ft_find_target_a(t_stack *node, t_stack *stack_a)
{
	long	best;
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = stack_a;
	best = LONG_MAX;
	while (TRUE)
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

/**
 * Fonction qui retourne le noeud de 'a' qui prendra la moins de coups a trier 
 * dans 'b'.
 */
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
	while (TRUE)
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
