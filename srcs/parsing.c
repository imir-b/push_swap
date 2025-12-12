/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:34 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 15:44:52 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '-' || args[i][j] == '+') && \
			!ft_isdigit((int)args[i][j + 1]))
			return (1);
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit((int)args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_duplicate(t_stack *stack_a)
{
	t_stack	*runner;
	t_stack	*current;

	if (!stack_a)
		return (0);
	current = stack_a;
	while (1)
	{
		runner = current->next;
		while (runner != current)
		{
			if (runner->number == current->number)
				return (1);
			runner = runner->next;
		}
		current = current->next;
		if (current == stack_a)
			break ;
	}
	return (0);
}

int	ft_parsing(t_stack **stack_a, char **args)
{
	long	nb;

	nb = 0;
	if (ft_check_args(args))
		return (1);
	while (*args)
	{
		nb = ft_atol(*args);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		ft_stackaddback(stack_a, ft_stacknew((int)nb));
		args++;
	}
	return (0);
}
