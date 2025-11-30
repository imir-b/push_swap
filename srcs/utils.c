/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:11:42 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/30 03:46:26 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	else
		return (0);
}

long int	ft_atol(char *nb)
{
	int			neg;
	long int	n;

	neg = 1;
	n = 0;
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '-' || *nb == '+')
	{
		if (*nb == '-')
			neg = -1;
		nb++;
	}
	while (*nb >= '0' && *nb <= '9')
	{
		n = n * 10 + *nb - '0';
		nb++;
	}
	return (neg * n);
}

t_stack	*ft_stacknew(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackaddback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->prev;
	last->next = new;
	new->prev = last;
	(*stack)->prev = new;
	new->next = *stack;
}
