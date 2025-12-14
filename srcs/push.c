/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:51:54 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/14 19:58:25 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!*dest)
	{
		*dest = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *dest;
		tmp->prev = (*dest)->prev;
		*dest = tmp;
		(*dest)->next->prev = tmp;
		(*dest)->prev->next = tmp;
	}
}

void	pa(t_stack **a, t_stack **b, int print)
{
	ft_push(a, b);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a, int print)
{
	ft_push(b, a);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
