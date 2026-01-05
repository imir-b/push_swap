/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 04:04:57 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/05 02:17:02 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Ecrit 'Error\n' dans STDERR (2) et return 1 en code erreur.
 */
int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (ERROR);
}

/**
 * Free propremment 'stack'
 */
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	if (current->prev)
		current->prev->next = NULL;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/**
 * Free propremment un tableau 'args'
 */
void	ft_free_split(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
