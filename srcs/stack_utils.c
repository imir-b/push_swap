/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 04:03:21 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/10 21:51:41 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		new->index = 0;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->prev;
	last->next = new;
	new->prev = last;
	(*stack)->prev = new;
	new->next = *stack;
	new->index = last->index + 1;
}

int	ft_stacksize(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (!stack)
		return (0);
	count = 0;
	tmp = stack;
	while (1)
	{
		tmp = tmp->next;
		count++;
		if (stack == tmp)
			break ;
	}
	return (count);
}

void	ft_set_index(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	if (!stack)
		return ;
	i = 0;
	tmp = stack;
	while (1)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
}
