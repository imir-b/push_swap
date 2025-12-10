/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/10 13:28:07 by vbleskin         ###   ########.fr       */
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

void	ft_algo_test(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
	{
		pb(b, a);
		if ((*b)->next == *b)
			continue ;
		if ((*b)->number < (*b)->prev->number)
			rb(b);
		if ((*b)->number < (*b)->next->number)
			sb(b);
	}
	ft_put_stack(*a, 'a');
	ft_sort_three(a);
	ft_put_stack(*a, 'a');
	ft_put_stack(*b, 'b');
	ft_push_back(a, b);
	ft_put_stack(*a, 'a');
	ft_put_stack(*b, 'b');
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
	ft_algo_test(&stack_a, &stack_b); //ALGO ICI
	ft_free_stack(&stack_a);
	return (0);
}
