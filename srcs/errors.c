/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 04:04:57 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/30 04:05:08 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*end;

	end = (*stack)->prev;
	while (*stack != end)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
	free(*stack);
}

void	ft_free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
