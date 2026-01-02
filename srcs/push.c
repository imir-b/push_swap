/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:51:54 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 04:47:07 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_add(t_stack **dest, t_stack *new)
{
	if (!*dest)
	{
		*dest = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = *dest;
		new->prev = (*dest)->prev;
		*dest = new;
		(*dest)->next->prev = new;
		(*dest)->prev->next = new;
	}
}

static void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	if ((*src)->next != *src)
	{
		*src = (*src)->next;
		tmp->prev->next = *src;
		(*src)->prev = tmp->prev;
	}
	else
		*src = NULL;
	ft_stack_add(dest, tmp);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	ft_push(a, b);
	if (print)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack **b, t_stack **a, int print)
{
	ft_push(b, a);
	if (print)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}
