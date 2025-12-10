/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/10 11:07:53 by vlad             ###   ########.fr       */
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
	int i = 0; //debug

	while (*a != (*a)->next && (*a)->next != (*a)->prev)
	{
		printf("--- count: %d ---\n", i); //debug
		i++; //debug
		ft_put_stack(*a, 'a'); //debug
		ft_put_stack(*b, 'b'); //debug
		printf("---instructions---\n"); //debug
		pb(b, a);
		if ((*b)->next == *b)
			continue ;
		if ((*b)->number < (*b)->prev->number)
			rb(b);
		if ((*b)->number < (*b)->next->number)
			sb(b);
	}
	while ((*a)->number > (*a)->next->number || (*a)->number > (*a)->prev->number)
	{
		printf("--- count: %d ---\n", i); //debug
		i++; //debug
		ft_put_stack(*a, 'a'); //debug
		ft_put_stack(*b, 'b'); //debug
		printf("---instructions---\n"); //debug
		ra(a);
	}
	//si stack a = 3 elements, rotate a jusqua avoir le bon ordre puis push b dans a 
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
	ft_free_stack(&stack_b);
	return (0);
}
