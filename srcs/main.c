/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/11 06:53:27 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	ft_put_stack(t_stack *stack, char c)
{
	t_stack	*tmp;

	if (!stack)
	{
		printf("-> Stack %c is empty\n", c);
		return ;
	}
	tmp = stack;
	printf("--- Stack %c ---\n", c);
	while (1)
	{
		printf("%i\n", stack->number);
		stack = stack->next;
		if (stack == tmp)
			break ;
	}
}

void	ft_algo(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = NULL;
	target = NULL;
	if (ft_stacksize(*a) < 3)
		ft_sort_two(a);
	while (ft_stacksize(*a) > 3)
	{
		ft_set_index(*a);
		ft_set_index(*b);
		cheapest = ft_find_cheapest(*a, *b);
		target = ft_find_target(cheapest, *b);
		ft_move_node(cheapest, target, a, b);
		pb(*b, *a);
	}
	ft_sort_three(a);
	ft_push_back(a, b);
	ft_put_stack(*a, 'a'); //debug
	ft_put_stack(*b, 'b'); //debug
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	if (ft_init_stack(&stack_a, ac, av))
		return (ft_error(), 1);
	ft_algo(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
