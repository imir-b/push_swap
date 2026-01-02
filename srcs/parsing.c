/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:34 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 05:34:34 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Verifie la validite des arguments si ce sont bien des nombres
 */
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
			return (ERROR);
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit((int)args[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/**
 * Verifie les duplicats de nombres dans 'stack_a'
 */
int	ft_check_duplicate(t_stack *stack_a)
{
	t_stack	*runner;
	t_stack	*current;

	if (!stack_a)
		return (SUCCESS);
	current = stack_a;
	while (TRUE)
	{
		runner = current->next;
		while (runner != current)
		{
			if (runner->number == current->number)
				return (ERROR);
			runner = runner->next;
		}
		current = current->next;
		if (current == stack_a)
			break ;
	}
	return (SUCCESS);
}

/**
 * Si les arguments 'args' sont valides et que les nombres des INT on les 
 * ajoute a la 'stack_a'.
 */
int	ft_parsing(t_stack **stack_a, char **args)
{
	long	nb;

	nb = 0;
	if (ft_check_args(args))
		return (ERROR);
	while (*args)
	{
		nb = ft_atol(*args);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ERROR);
		ft_stackaddback(stack_a, ft_stacknew((int)nb));
		args++;
	}
	return (SUCCESS);
}
