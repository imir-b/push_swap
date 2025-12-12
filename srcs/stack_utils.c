/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 04:03:21 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 15:45:01 by vlad             ###   ########.fr       */
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

int	ft_init_stack(t_stack **stack_a, int ac, char **av)
{
	char	**args;
	int		i;

	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			return (1);
		if (ft_parsing(stack_a, args))
			return (ft_free_stack(stack_a), ft_free_split(args), 1);
		ft_free_split(args);
		i++;
	}
	if (ft_check_duplicate(*stack_a))
		return (ft_free_stack(stack_a), 1);
	return (0);
}
