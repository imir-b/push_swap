/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:51:54 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/30 05:08:35 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **dest, t_stack **src)
{
	int	tmp;

	tmp = (*src)->number;
	(*src)->number = (*dest)->number;
	(*dest)->number = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	ft_putstr_fd("pb\n", 1);
}
