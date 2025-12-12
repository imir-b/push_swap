/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 04:04:57 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 23:04:27 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void    ft_free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current;

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
